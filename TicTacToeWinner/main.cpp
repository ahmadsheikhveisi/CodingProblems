/* COPYRIGHT
 */

#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

template <std::size_t N = 3>
class Solution {
 private:
  static constexpr size_t num_of_players{2};
  static constexpr size_t move_row_idx{0};
  static constexpr size_t move_clmn_idx{1};
  static constexpr std::string_view game_pending{"Pending"};
  static constexpr std::string_view game_draw{"Draw"};
  std::array<std::string_view, num_of_players> const players{"A", "B"};

  using Board = std::vector<std::vector<std::string_view>>;
  using Move = std::vector<int>;
  using RowClumn = std::vector<std::string_view>;

  int get_row_idx(Move const& move) { return move[move_row_idx]; }

  int get_column_idx(Move const& move) { return move[move_clmn_idx]; }

  std::string_view CalculateMove(Move const& move, Board const& board,
                                 size_t move_count) {
    auto player = players[move_count % 2];
    // check the row
    const auto& row = board[get_row_idx(move)];
    if (std::all_of(begin(row), end(row),
                    [player](std::string_view sq) { return sq == player; })) {
      return player;
    }
    // check the column
    if (std::all_of(begin(board), end(board),
                    [player, clmn = get_column_idx(move)](RowClumn sq) {
                      return sq[clmn] == player;
                    })) {
      return player;
    }
    // check diag
    if (get_column_idx(move) == get_row_idx(move)) {
      bool found_diag{true};
      for (size_t cnt{0}; cnt < N; ++cnt) {
        found_diag = found_diag && (board[cnt][cnt] == player);
        if (found_diag == false) {
          break;
        }
      }
      if (found_diag) {
        return player;
      }
    }
    // check counter diag
    if (get_column_idx(move) == N - 1 - get_row_idx(move)) {
      bool found_counter_diag{true};
      for (size_t cnt{0}; cnt < N; ++cnt) {
        found_counter_diag =
            found_counter_diag && (board[cnt][N - 1 - cnt] == player);
        if (found_counter_diag == false) {
          break;
        }
      }
      if (found_counter_diag) {
        return player;
      }
    }
    // check for draw
    if (move_count >= N * N - 1) {
      return game_draw;
    }
    return game_pending;
  }

 public:
  std::string_view tictactoe(std::vector<std::vector<int>> const& moves) {
    Board board(N, RowClumn(N, " "));
    std::string_view game_state{game_pending};
    size_t move_count{0};
    for (const auto& move : moves) {
      board[get_row_idx(move)][get_column_idx(move)] = players[move_count % 2];
      game_state = CalculateMove(move, board, move_count);
      ++move_count;
    }
    return game_state;
  }
};

int main() {
  auto obj = Solution<3>();
  std::cout << obj.tictactoe({{0, 0},
                              {1, 1},
                              {2, 0},
                              {1, 0},
                              {1, 2},
                              {2, 1},
                              {0, 1},
                              {0, 2},
                              {2, 2}})
            << '\n';
  std::cout << obj.tictactoe({{0, 0}, {1, 1}, {0, 1}, {0, 2}, {1, 0}, {2, 0}})
            << '\n';
  std::cout << obj.tictactoe({{0, 0}, {2, 0}, {1, 1}, {2, 1}, {2, 2}}) << '\n';
  return 0;
}
