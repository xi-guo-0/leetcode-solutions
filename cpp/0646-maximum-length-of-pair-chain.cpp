class Solution {
public:
  int findLongestChain(vector<vector<int>> &pairs) {
    vector<int> dp;
    sort(pairs.begin(), pairs.end(),
         [](const vector<int> &a, const vector<int> &b) {
           return a[1] != b[1] ? a[1] < b[1] : a[0] < b[0];
         });
    dp.push_back(pairs.front()[1]);
    for (const vector<int> &p : pairs) {
      for (int i = 1; i < dp.size(); i++) {
        if (dp[i - 1] < p[0] && p[1] < dp[i])
          dp[i] = p[1];
      }
      if (dp.back() < p[0])
        dp.push_back(p[1]);
    }
    return dp.size();
  }
};
