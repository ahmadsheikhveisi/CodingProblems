/**
 * Copyright
 */

#ifndef GRAPH_GRAPH_HPP_
#define GRAPH_GRAPH_HPP_

#include <functional>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

class Graph {
 public:
  class Edge {
   public:
    explicit Edge(int cost = 0, int length = 0)
        : cost_{cost}, length_{length} {}
    int cost_;
    int length_;
  };
  class Vertex {
   public:
    explicit Vertex(const std::string& name)
        : name_{name}, visited_{false}, adjacency_list_{}, parents_{} {}
    const std::string& name_;
    bool visited_;
    // the reason why map is not used is map on vertex (custom or edge) is not
    // possible. and if we use only int for cost of the edge, we need more than
    // one edge with a cost the only solution might be multimap, which still
    // doesn't help in searching.
    std::vector<std::pair<std::shared_ptr<Vertex>, Edge>> adjacency_list_;
    std::vector<std::pair<std::shared_ptr<Vertex>, Edge>> parents_;

    void AddVertex(std::shared_ptr<Vertex> to_vertex, Edge edge) {
      auto new_edge = std::make_pair(to_vertex, edge);
      adjacency_list_.emplace_back(new_edge);
    }
  };

  explicit Graph(bool directed = true) : directed_{directed}, graph_{} {}

  const bool directed_;
  std::unordered_map<std::string, std::shared_ptr<Vertex>> graph_{};

  std::shared_ptr<Vertex> FindVertedByName(std::string_view name) {
    auto it = graph_.find(std::string(name));
    if (it == end(graph_)) {
      return nullptr;
    }
    return it->second;
  }

  void Reset() {
    for (auto& vertex : graph_) {
      vertex.second->visited_ = false;
    }
  }
  bool AddVertices(std::initializer_list<std::string> vertices) {
    for (auto vertx : vertices) {
      if (!AddVertex(vertx)) {
        return false;
      }
    }
    return true;
  }

  bool AddVertex(std::string const& name) {
    if (graph_.find(name) != end(graph_)) {
      return false;
    }
    graph_[name] = nullptr;
    graph_[name] = std::make_shared<Vertex>(graph_.find(name)->first);
    return true;
  }

  bool AddEdge(std::string const& from, std::string const& to, int cost = 0,
               int length = 0) {
    auto from_it = graph_.find(from);
    auto to_it = graph_.find(to);
    if ((from_it == end(graph_)) || (to_it == end(graph_))) {
      return false;
    }
    from_it->second->AddVertex(to_it->second, Edge{cost, length});
    if (!directed_) {
      to_it->second->AddVertex(from_it->second, Edge{cost, length});
    } else {
      to_it->second->parents_.push_back(std::make_pair(from_it->second, Edge{cost, length}));
    }
    return true;
  }

  using Visit = std::function<bool(std::shared_ptr<Vertex>)>;
  void BreadthFirstSearch(std::shared_ptr<Vertex> vertex, Visit visit) {
    std::queue<std::shared_ptr<Vertex>> mqueue;
    vertex->visited_ = true;
    mqueue.emplace(vertex);
    while (!mqueue.empty()) {
      auto vrtx = mqueue.front();
      mqueue.pop();
      if (!visit(vrtx)) {
        return;
      }
      for (auto& [neighbor, _] : vrtx->adjacency_list_) {
        (void)_;
        if (!neighbor->visited_) {
          mqueue.push(neighbor);
          neighbor->visited_ = true;
        }
      }
    }
  }

  bool DepthFirstSearch(std::shared_ptr<Vertex> vertex, Visit visit) {
    vertex->visited_ = true;
    for (auto& [neighbor, _] : vertex->adjacency_list_) {
      (void)_;
      if (neighbor->visited_ == false) {
        if (!DepthFirstSearch(neighbor, visit)) {
          return false;
        }
      }
    }
    return visit(vertex);
  }

  std::vector<std::shared_ptr<Vertex>> BidirectionalSearch(
      std::shared_ptr<Vertex> start, std::shared_ptr<Vertex> target) {
    std::vector<std::shared_ptr<Vertex>> path;
    if ((start == nullptr) || (target == nullptr)) {
      return path;
    }
    std::queue<std::shared_ptr<Vertex>> squeue;
    squeue.push(start);
    std::queue<std::shared_ptr<Vertex>> tqueue;
    tqueue.push(target);

    std::unordered_set<std::string_view> svisited;
    svisited.insert(start->name_);
    std::unordered_set<std::string_view> tvisited;
    tvisited.insert(target->name_);

    std::unordered_map<std::string_view, std::string_view> sparent;
    sparent[start->name_] = {};
    std::unordered_map<std::string_view, std::string_view> tparent;
    tparent[target->name_] = {};

    while (!squeue.empty() && !tqueue.empty()) {
      BidirectionalSearchBreadthFirst(std::ref(squeue), std::ref(sparent),
                                      std::ref(svisited));
      BidirectionalSearchBreadthFirst(std::ref(tqueue), std::ref(tparent),
                                      std::ref(tvisited));
      // Is intersected
      std::string_view intersect{};
      // std::set_intersection only works on sorted containers
      for (auto sv : svisited) {
        if (tvisited.find(sv) != end(tvisited)) {
          intersect = sv;
          break;
        }
      }

      if (!intersect.empty()) {
        path.push_back(FindVertedByName(intersect));
        auto current_vx_name = intersect;
        while (!sparent[current_vx_name].empty()) {
          path.push_back(FindVertedByName(sparent[current_vx_name]));
          current_vx_name = sparent[current_vx_name];
        }
        std::reverse(begin(path), end(path));
        current_vx_name = intersect;
        while (!tparent[current_vx_name].empty()) {
          path.push_back(FindVertedByName(tparent[current_vx_name]));
          current_vx_name = tparent[current_vx_name];
        }
        break;
      }
    }

    return path;
  }

 private:
  void BidirectionalSearchBreadthFirst(
      std::reference_wrapper<std::queue<std::shared_ptr<Vertex>>> rqueue,
      std::reference_wrapper<
          std::unordered_map<std::string_view, std::string_view>>
          rparent,
      std::reference_wrapper<std::unordered_set<std::string_view>> rvisited) {
    auto& visited = rvisited.get();
    auto& parent = rparent.get();
    auto& mqueue = rqueue.get();
    std::shared_ptr<Vertex> parent_vertex{nullptr};
    if (!mqueue.empty()) {
      static_cast<void>(PutUnvisitedNeighborsInQueue(
          rqueue,
          [&parent_vertex](std::shared_ptr<Vertex> current_vertex) {
            parent_vertex = current_vertex;
            return true;
          },
          [&visited, &parent, &parent_vertex](std::shared_ptr<Vertex> vertex) {
            visited.insert(vertex->name_);
            parent[vertex->name_] = parent_vertex->name_;
          },
          [&visited](std::shared_ptr<Vertex> vertex) {
            return visited.find(vertex->name_) != end(visited);
          }));
    }
  }

  using SetVisited = std::function<void(std::shared_ptr<Vertex>)>;
  using IsVisited = std::function<bool(std::shared_ptr<Vertex>)>;
  bool PutUnvisitedNeighborsInQueue(
      std::reference_wrapper<std::queue<std::shared_ptr<Vertex>>> rqueue,
      Visit const& visit,
      SetVisited set_visited =
          [](std::shared_ptr<Vertex> vrtx) { vrtx->visited_ = true; },
      IsVisited is_visited =
          [](std::shared_ptr<Vertex> vrtx) { return vrtx->visited_; }) {
    auto& mqueue = rqueue.get();
    auto vertex = mqueue.front();
    mqueue.pop();
    if (!visit(vertex)) {
      return false;
    }
    for (auto& [neighbor, _] : vertex->adjacency_list_) {
      (void)_;
      if (!is_visited(neighbor)) {
        set_visited(neighbor);
        mqueue.push(neighbor);
      }
    }
    return true;
  }
};

#endif  // GRAPH_GRAPH_HPP_
