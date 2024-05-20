class Solution {
public:
  int findComplement(int num) {
    if (num == 0)
      return 1;
    return (~num) & ((1L << (static_cast<int>(log2(num)) + 1)) - 1);
  }
};
