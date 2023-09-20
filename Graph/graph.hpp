/**
 * Copyright
*/

#ifndef GRAPH_GRAPH_HPP_
#define GRAPH_GRAPH_HPP_

#include <functional>
#include <memory>
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>

class Graph {
 public: 
 class Edge {
    public:
    Edge(int cost = 0) : cost_{cost} {}
    int cost_;
 };
 class Vertex {
    public:
    Vertex(std::string name) : name_{name}, adjacency_list_{}, visited_{false} {}
    std::string name_;
    bool visited_;
    // the reason why map is not used is map on vertex (custom or edge) is not possible.
    // and if we use only int for cost of the edge, we need more than one edge with a cost
    // the only solution might be multimap, which still doesn't help in searching.
    std::vector<std::pair<std::shared_ptr<Vertex>, Edge>> adjacency_list_;
 };

 std::unordered_map<std::string, std::shared_ptr<Vertex>> graph{};

 void Reset() {
    for (auto& vertex : graph) {
        vertex.second->visited_ = false;
    }
 }

 bool AddVertex(std::string const& name) {
    if (graph.find(name) != end(graph)) {
        return false;
    }
    graph[name] = std::make_shared<Vertex>(name);
    return true;
 }

 bool AddEdge(std::string const& from, std::string const& to, int cost) {
    auto from_it = graph.find(from);
    auto to_it = graph.find(to);
    if ((from_it == end(graph)) || (to_it == end(graph))) {
        return false;
    }
    auto new_edge = std::make_pair(to_it->second, Edge{cost});
    from_it->second->adjacency_list_.emplace_back(new_edge);

    return true;
 }

 using Visit = std::function<bool(std::shared_ptr<Vertex>)>;
 void BreadthFirstSearch(std::shared_ptr<Vertex> vertex, Visit visit) {
    std::queue<std::shared_ptr<Vertex>> mqueue;
    vertex->visited_ = true;
    mqueue.emplace(vertex);
    while(!mqueue.empty()) {
        auto vrtx = mqueue.front();
        mqueue.pop();
        if (!visit(vrtx)) {
            return;
        }
        for (auto neighbor : vrtx->adjacency_list_) {
            if (!neighbor.first->visited_) {
                mqueue.push(neighbor.first);
                neighbor.first->visited_ = true;
            }
        }
    }
 }

};

#endif  // GRAPH_GRAPH_HPP_
