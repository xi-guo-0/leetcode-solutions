#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool validTicTacToe(vector<string> &board) {
    int xCount = 0, oCount = 0;
    for (const string &row : board) {
      xCount += count(row.begin(), row.end(), 'X');
      oCount += count(row.begin(), row.end(), 'O');
    }

    if (oCount != xCount && oCount != xCount - 1) {
      return false;
    }

    if (win(board, 'X') && oCount != xCount - 1) {
      return false;
    }
    if (win(board, 'O') && oCount != xCount) {
      return false;
    }

    return true;
  }

private:
  bool win(const vector<string> &board, char player) {
    for (int i = 0; i < 3; ++i) {
      if (board[i][0] == player && board[i][1] == player &&
          board[i][2] == player) {
        return true;
      }
      if (board[0][i] == player && board[1][i] == player &&
          board[2][i] == player) {
        return true;
      }
    }

    if (board[0][0] == player && board[1][1] == player &&
        board[2][2] == player) {
      return true;
    }
    if (board[0][2] == player && board[1][1] == player &&
        board[2][0] == player) {
      return true;
    }

    return false;
  }
};

int main() {
  Solution solution;
  vector<string> board = {"O  ", "   ", "   "};
  cout << boolalpha << solution.validTicTacToe(board) << endl;
  board = {"XOX", " X ", "   "};
  cout << boolalpha << solution.validTicTacToe(board) << endl;
  board = {"XOX", "O O", "XOX"};
  cout << boolalpha << solution.validTicTacToe(board) << endl;
  return 0;
}
