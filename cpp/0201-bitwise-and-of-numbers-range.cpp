class Solution {
public:
  int rangeBitwiseAnd(const int m, const int n) {
    int res = 0;
    int k = 1 << (sizeof(int) * 8 - 2);
    while (0 < k && (k & m) == (k & n)) {
      res |= (k & m);
      k >>= 1;
    }
    return res;
  }
};
