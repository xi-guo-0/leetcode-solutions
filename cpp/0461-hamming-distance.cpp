class Solution {
public:
  int hammingDistance(const int x, const int y) {
    bitset<8 * sizeof(int)> bits(x ^ y);
    return bits.count();
  }
};
