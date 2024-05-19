class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num == 1) {
      return true;
    }
    long long i = num / 2;
    while (i * i > num)
      i = (i + num / i) / 2;
    return i * i == num;
  }
};
