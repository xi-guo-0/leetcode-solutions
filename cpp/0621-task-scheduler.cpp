class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    unordered_map<char, int> umap;
    int count = 0, same = 0, res = 0;
    for (char c : tasks) {
      ++umap[c];
      count = max(count, umap[c]);
    }
    for (auto m : umap) {
      if (m.second == count) {
        ++same;
      }
    }
    res = (count - 1) * (n + 1) + same;
    return max((int)tasks.size(), res);
  }
};
