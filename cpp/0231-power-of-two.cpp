class Solution {
public:
  bool isPowerOfTwo(int n) {
    return bitset<32>(n).count() == 1 && n != INT_MIN;
  }
};
