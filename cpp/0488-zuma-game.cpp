class Solution {
public:
  int findMinStep(string board, string hand) {
    unordered_map<string, int> cache;
    vector<int> freq(26, 0);
    for (char c : hand)
      freq[c - 'A']++;
    return dfs(board, freq, cache);
  }

  int dfs(string board, vector<int> &freq, unordered_map<string, int> &cache) {
    string key = board + "#" + serialize(freq);
    if (cache.count(key))
      return cache[key];
    if (board.empty())
      return 0;
    int r = INT_MAX;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < freq.size(); ++j) {
        if (freq[j] &&
            (board[i] - 'A' == j ||
             (i > 0 && board[i] == board[i - 1] && board[i] - 'A' != j))) {
          string newBoard =
              board.substr(0, i) + string(1, j + 'A') + board.substr(i);
          --freq[j];
          newBoard = updateBoard(newBoard);
          int steps = dfs(newBoard, freq, cache);
          if (steps != -1)
            r = min(r, steps + 1);
          ++freq[j];
        }
      }
    }
    return cache[key] = (r == INT_MAX ? -1 : r);
  }

  string updateBoard(string board) {
    int start = 0, end = 0;
    while (start < board.size()) {
      while (end < board.size() && board[start] == board[end])
        ++end;
      if (end - start >= 3) {
        board = board.substr(0, start) + board.substr(end);
        return updateBoard(board);
      } else {
        start = end;
      }
    }
    return board;
  }

  string serialize(vector<int> &freq) {
    string key = "";
    for (int i = 0; i < freq.size(); ++i) {
      if (freq[i] > 0)
        key += to_string((char)i + 'A') + to_string(freq[i]);
    }
    return key;
  }
};
