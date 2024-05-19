#include <vector>

using namespace std;

class Solution {
public:
  int countBattleships(vector<vector<char>> &board) {
    int ans = 0;
    for (int r = 0; r < board.size(); ++r) {
      for (int c = 0; c < board[0].size(); ++c) {
        if (board[r][c] == battleship &&
            (r == 0 || board[r - 1][c] != battleship) &&
            (c == 0 || board[r][c - 1] != battleship)) {
          ++ans;
        }
      }
    }
    return ans;
  }

private:
  static constexpr char battleship = 'X';
};
