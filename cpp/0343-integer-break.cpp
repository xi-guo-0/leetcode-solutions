class Solution {
public:
  int integerBreak(int n) {
    if (n == 2) {
      return 1;
    } else if (n == 3) {
      return 2;
    } else if (n == 4) {
      return 4;
    }

    int numsOf3 = n / 3;
    if (n % 3 == 1) {
      return static_cast<int>(
          (static_cast<long long>(pow(3, numsOf3 - 1)) * 4) % BM);
    } else if (n % 3 == 2) {
      return static_cast<int>((static_cast<long long>(pow(3, numsOf3)) * 2) %
                              BM);
    } else {
      return static_cast<int>((static_cast<long long>(pow(3, numsOf3)) % BM));
    }
  }

private:
  static constexpr int M = 1000000007;
  static constexpr long long BM = 1000000007LL;
};
