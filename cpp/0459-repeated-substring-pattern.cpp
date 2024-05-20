class Solution {
public:
  bool repeatedSubstringPattern(const string &s) {
    const string ss(move(s + s));
    return ss.substr(1, ss.size() - 2).find(s) != string::npos;
  }
};
