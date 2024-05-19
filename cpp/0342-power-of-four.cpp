class Solution {
public:
  bool isPowerOfFour(int num) {
    if (bitset<32>(num).count() != 1 || num == INT_MIN) {
      return false;
    }
    while (4 < num)
      num >>= 2;
    return num == 4 || num == 1;
  }
};
