class Solution {
public:
  int findMaximumXOR(const vector<int> &nums) {
    int ans = 0, mask = 0;
    for (int i = 31; 0 <= i; --i) {
      mask |= (1 << i);
      unordered_set<int> prefix_set;
      for (const auto &num : nums) {
        prefix_set.insert(mask & num);
      }
      int spare = ans | (1 << i);
      for (const auto &num : prefix_set) {
        if (prefix_set.count(spare ^ num)) {
          ans = spare;
          break;
        }
      }
    }
    return ans;
  }
};
