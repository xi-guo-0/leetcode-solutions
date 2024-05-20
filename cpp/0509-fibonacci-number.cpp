class Solution {
public:
  int fib(int n) {
    if (n < 2) {
      return n;
    } else {
      int a = 0;
      int b = 1;
      int t;
      for (int i = 0; i < n; ++i) {
        t = a + b;
        a = b;
        b = t;
      }
      return a;
    }
  }
};
