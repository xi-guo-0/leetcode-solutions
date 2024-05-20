class Solution {
private:
  bitset<(1 << 20)> used, val;

public:
  bool canIWin(int const maxChoosableInteger, int const desiredTotal) {
    if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) {
      return false;
    } else if (desiredTotal <= maxChoosableInteger) {
      return true;
    }
    return helper(maxChoosableInteger, desiredTotal, 0u);
  }

  bool helper(int const maxChoosableInteger, int const desiredTotal,
              unsigned const mask) {
    if (used[mask]) {
      return val[mask];
    }
    unsigned cur = 1;
    for (int i = maxChoosableInteger; 0 < i; --i, cur <<= 1) {
      if ((mask & cur) == 0) {
        if (desiredTotal <= i ||
            !helper(maxChoosableInteger, desiredTotal - i, mask | cur)) {
          return used[mask] = val[mask] = 1;
        }
      }
    }
    used[mask] = 1, val[mask] = 0;
    return false;
  }
};
