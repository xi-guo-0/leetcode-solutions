class Solution {
public:
  vector<vector<int>> findSubsequences(const vector<int> &nums) {
    vector<vector<int>> v;
    dfs(nums, 0, v);
    sort(v.begin(), v.end());
    vector<vector<int>> res;
    for (int i = 0; i < v.size(); i++) {
      if (v[i].size() < 2)
        continue;
      else if (0 < i && v[i - 1] == v[i])
        continue;
      res.push_back(v[i]);
    }
    return res;
  }

private:
  void dfs(const vector<int> &nums, const int k, vector<vector<int>> &v) {
    if (k == nums.size())
      return;
    const int n = v.size();
    for (int i = 0; i < n; i++) {
      if (v[i].back() <= nums[k]) {
        auto u = v[i];
        u.push_back(nums[k]);
        v.push_back(u);
      }
    }
    v.push_back({nums[k]});
    dfs(nums, k + 1, v);
  }
};
