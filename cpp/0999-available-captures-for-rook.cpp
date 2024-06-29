#include <vector>

using namespace std;

class Solution {
public:
  int numRookCaptures(vector<vector<char>> &board) {
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    for (i = 0; i < 8; ++i) {
      for (j = 0; j < 8; ++j) {
        if (board[i][j] == 'R')
          goto FIND;
      }
    }
  FIND:

    for (k = j - 1; 0 <= k && board[i][k] == '.'; --k)
      ;
    if (0 <= k && board[i][k] == 'p')
      ++count;
    for (k = j + 1; k < 8 && board[i][k] == '.'; ++k)
      ;
    if (k < 8 && board[i][k] == 'p')
      ++count;
    for (k = i - 1; 0 <= k && board[k][j] == '.'; --k)
      ;
    if (0 <= k && board[k][j] == 'p')
      ++count;
    for (k = i + 1; k < 8 && board[k][j] == '.'; ++k)
      ;
    if (k < 8 && board[k][j] == 'p')
      ++count;
    return count;
  }
};

int main() { return 0; }
