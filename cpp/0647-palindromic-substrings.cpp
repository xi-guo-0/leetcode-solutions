class Solution {
public:
  int countSubstrings(const string &s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
      res += countSinglePoint(s, i, i);
      res += countSinglePoint(s, i, i + 1);
    }
    return res;
  }

private:
  int countSinglePoint(const string &s, int i, int j) {
    if (i > j || i < 0 || j >= s.size())
      return 0;
    int res = 0;
    while (i >= 0 && j < s.size() && s[i] == s[j]) {
      --i;
      ++j;
      ++res;
    }
    return res;
  }
};
