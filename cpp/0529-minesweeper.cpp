class Solution {
public:
  vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                   vector<int> &click) {
    R = board.size();
    C = board[0].size();
    if (legal(click[0], click[1])) {
      dfs(board, click[0], click[1]);
    }
    return board;
  }

private:
  static int constexpr K = 8;
  static int constexpr dr[K] = {-1, -1, -1, 0, 1, 1, 1, 0};
  static int constexpr dc[K] = {-1, 0, 1, 1, 1, 0, -1, -1};
  int R;
  int C;
  bool legal(int const r, int const c) {
    return 0 <= r && r < R && 0 <= c && c < C;
  }

  void dfs(vector<vector<char>> &board, int const r, int const c) {
    char const ch = board[r][c];
    if (ch == 'M') {
      board[r][c] = 'X';
    } else if (ch == 'E') {
      int number_of_adjacent_mines = 0;
      for (int k = 0; k < K; ++k) {
        int const nr = r + dr[k];
        int const nc = c + dc[k];
        if (legal(nr, nc) && (board[nr][nc] == 'M' || board[nr][nc] == 'X')) {
          ++number_of_adjacent_mines;
        }
      }
      if (number_of_adjacent_mines == 0) {
        board[r][c] = 'B';
        for (int k = 0; k < K; ++k) {
          int const nr = r + dr[k];
          int const nc = c + dc[k];
          if (legal(nr, nc) && (board[nr][nc] == 'E')) {
            dfs(board, nr, nc);
          }
        }
      } else {
        board[r][c] = '0' + number_of_adjacent_mines;
      }
    }
  }
};
