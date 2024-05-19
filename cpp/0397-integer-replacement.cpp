class Solution {
public:
  unordered_map<int, int> memo;
  int integerReplacement(const int n) {
    if (n == 1)
      return 0;
    else if (n == numeric_limits<int>::max())
      return 32;
    else if (memo.count(n))
      return memo[n];
    int ans = 0;
    if (n & 0x1) {
      ans = 1 + min(integerReplacement(n - 1), integerReplacement(n + 1));
    } else {
      ans = 1 + integerReplacement(n >> 1);
    }
    memo[n] = ans;
    return ans;
  }
};
