class Solution {
public:
  int largestPalindrome(int n) {
    if (n == 1)
      return 9;
    int hi = pow(10, n) - 1, lo = pow(10, n - 1), kk = 1337;
    for (int i = hi; i >= lo; --i) {
      string s = to_string(i);
      long long int ll = stoll(s + string(s.rbegin(), s.rend()));
      for (int j = hi; j >= sqrt(ll); --j) {
        if (ll % j == 0)
          return ll % kk;
      }
    }
    return 0;
  }
};
