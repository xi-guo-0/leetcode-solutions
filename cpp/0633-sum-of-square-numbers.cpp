class Solution {
public:
  bool judgeSquareSum(const int c) {
    for (int i = 0; i <= sqrt(c); i++) {
      double b = sqrt(static_cast<double>(c - i * i));
      if (b == static_cast<int>(b))
        return true;
    }
    return false;
  }
};
