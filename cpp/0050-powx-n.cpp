class Solution {
public:
  double myPow(double x, long long n) {

    return n < 0 ? 1 / fastPow(x, -n) : fastPow(x, n);
  }

  static double fastPow(double x, long long n) {
    if (n == 0) {
      return 1.0;
    } else if (n == 1) {
      return x;
    }
    double t = fastPow(x, n / 2);
    return n & 1 ? t * t * x : t * t;
  }
};
