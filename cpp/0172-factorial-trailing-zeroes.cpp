class Solution {
public:
  int trailingZeroes(int n) {
    int cnt = 0;
    while (5 <= n) {
      cnt += n / 5;
      n /= 5;
    }
    return cnt;
  }
};
