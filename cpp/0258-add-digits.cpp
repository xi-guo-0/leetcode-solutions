class Solution {
public:
  int addDigits(const int num) { return (num - 1) % 9 + 1; }
};
