class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    bitset<32> bits(n);
    for (size_t i = 0; i < 16; i++) {
      bool t = bits[i];
      bits[i] = bits[31 - i];
      bits[31 - i] = t;
    }
    return bits.to_ulong();
  }
};
