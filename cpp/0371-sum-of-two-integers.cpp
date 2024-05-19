class Solution {
public:
  int getSum(int a, int b) {
    int res = a;
    int x = a ^ b;
    int forward = (a & b) << 1;
    if (0 != forward) {
      res = getSum(x, forward);
    } else {
      res = x;
    }
    return res;
  }
};
