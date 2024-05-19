class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
      return 1;
    }
    int ans = 10;
    for (int i = 2, t = 9, k = 9; i <= n; ++i, --k) {
      t *= k;
      ans += t;
    }
    return ans;
  }
};
