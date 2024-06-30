class Solution {
public:
  int bitwiseComplement(int n) {
    if (n == 0) {
      return 1;
    }
    int tmp = n;
    int bits = 0;
    while (tmp != 0) {
      tmp >>= 1;
      bits = (bits << 1) + 1;
    }
    return (~n) & bits;
  }
};

int main() { return 0; }
