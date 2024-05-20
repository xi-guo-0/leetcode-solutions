class Solution {
public:
  int arrangeCoins(int n) {
    long long m = n;
    m *= 2;
    return ((int)(floor(sqrt(1 + (m << 2)))) - 1) >> 1;
  }
};
