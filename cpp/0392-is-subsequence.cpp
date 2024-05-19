class Solution {
public:
  bool isSubsequence(const string &s, const string &t) {
    auto is = s.begin();
    for (auto it = t.begin(); is != s.end() && it != t.end(); it++)
      if (*is == *it)
        is++;
    return is == s.end();
  }
};
