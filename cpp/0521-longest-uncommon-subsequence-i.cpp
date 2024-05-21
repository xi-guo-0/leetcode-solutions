class Solution {
public:
  int findLUSlength(string a, string b) {
    return a == b ? -1 : std::max(a.length(), b.length());
  }
};
