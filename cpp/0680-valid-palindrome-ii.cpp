class Solution {
public:
  bool validPalindrome(const string &s) {
    int i = 0, j = s.size() - 1;
    while (i < j && s[i] == s[j]) {
      i++;
      j--;
    }
    if (i >= j) {
      return true;
    }
    int p = i, q = j - 1, r = i + 1, t = j;
    while (p < q && s[p] == s[q]) {
      p++;
      q--;
    }
    if (p >= q) {
      return true;
    }
    while (r < t && s[r] == s[t]) {
      r++;
      t--;
    }
    if (r >= t) {
      return true;
    }
    return false;
  }
};
