class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    if (n < ((k + 1) * k) / 2 || ((2 * sz - k - 1) * k) / 2 < n) {
      return vector<vector<int>>();
    }
    vector<vector<int>> result;
    vector<int> line;
    vector<bool> used(n, false);
    dfs(result, line, 1, k, n);
    return result;
  }

  void dfs(vector<vector<int>> &result, vector<int> &line, int i, int k,
           int n) {
    if (n == 0 && line.size() == k) {
      result.push_back(line);
    }
    if (n > 0) {
      for (int j = i; j < sz; j++) {
        line.push_back(j);
        dfs(result, line, j + 1, k, n - j);
        line.pop_back();
      }
    }
  }

private:
  static const int sz = 10;
};
