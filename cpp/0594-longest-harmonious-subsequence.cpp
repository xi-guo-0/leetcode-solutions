class Solution {
public:
  int findLHS(const vector<int> &nums) {
    int result = 0;
    map<int, int> dict;
    for (const auto &n : nums)
      if (dict.count(n))
        dict[n]++;
      else
        dict[n] = 1;
    for (const auto &item : dict)
      if (dict.count(item.first + 1))
        result = max(result, item.second + dict[item.first + 1]);
    return result;
  }
};
