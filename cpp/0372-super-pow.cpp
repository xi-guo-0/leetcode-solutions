class Solution {
public:
  int superPow(int a, vector<int> &b) {
    int result = 1;
    for (int digit : b) {
      result =
          (modularPow(result, 10, 1337) * modularPow(a, digit, 1337)) % 1337;
    }
    return result;
  }

private:
  int modularPow(int base, int exponent, int modulus) {
    int result = 1;
    base %= modulus;
    while (exponent > 0) {
      if (exponent % 2 == 1) {
        result = (result * base) % modulus;
      }
      exponent >>= 1;
      base = (base * base) % modulus;
    }
    return result;
  }
};
