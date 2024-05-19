// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return
// 0
int guess(int num);

class Solution {
public:
  int guessNumber(int n) {
    int l = 1, r = n, m = l + (r - l) / 2, g = 0;
    ;
    while ((g = guess(m))) {
      if (g == 1)
        l = m + 1;
      else
        r = m - 1;
      m = l + (r - l) / 2;
    }
    return m;
  }
};
