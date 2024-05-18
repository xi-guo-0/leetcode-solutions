class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {
    if (board.size() == 0 || board[0].size() == 0) {
      return;
    }
    for (int i = 0; i < board.size(); i++)
      for (int j = 0; j < board[0].size(); j++)
        count(board, i, j);
    refresh(board);
  }

private:
  void count(vector<vector<int>> &board, int i, int j) {
    int m = board.size();
    int n = board[0].size();
    vector<pair<int, int>> neighbours{
        {i - 1, j - 1}, {i - 1, j},     {i - 1, j + 1}, {i, j - 1},
        {i, j + 1},     {i + 1, j - 1}, {i + 1, j},     {i + 1, j + 1}};
    for (int k = 0; k < neighbours.size(); k++) {
      int r = neighbours[k].first;
      int c = neighbours[k].second;
      if (0 <= r && r < m && 0 <= c && c < n && board[r][c] & 0x1)
        board[i][j] |= 1 << (k + 1);
    }
  }

  void refresh(vector<vector<int>> &board) {
    for (auto &line : board) {
      for (auto &ele : line) {
        bitset<32> bits(ele >> 1);
        auto n = bits.count();
        if (ele & 0x1) {
          ele = (n < 2 || n > 3) ? 0 : 1;
        } else {
          ele = (n == 3) ? 1 : 0;
        }
      }
    }
  }
};
