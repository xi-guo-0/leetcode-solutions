class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    unordered_map<int, int> dict;
    dict.emplace(0, -1);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < nums.size(); ++i) {
      cnt = cnt + (nums[i] == 1 ? 1 : -1);
      if (dict.count(cnt)) {
        ans = max(ans, i - dict[cnt]);
      } else {
        dict.emplace(cnt, i);
      }
    }
    return ans;
  }
};
