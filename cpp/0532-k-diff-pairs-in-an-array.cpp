class Solution {
public:
  int findPairs(const vector<int> &nums, int k) {
    map<int, int> m;
    int result = 0;
    for (const auto &n : nums)
      if (m.find(n) != m.end())
        m[n]++;
      else
        m[n] = 1;
    if (k > 0) {
      for (auto it = m.begin(); it != m.end(); it++)
        if (m.find(it->first + k) != m.end())
          result++;
    } else if (k == 0) {
      for (auto it = m.begin(); it != m.end(); it++)
        result += it->second > 1;
    }
    return result;
  }
};
