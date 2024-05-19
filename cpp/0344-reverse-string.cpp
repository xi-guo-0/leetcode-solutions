class Solution {
public:
  void reverseString(vector<char> &s) {
    int n = s.size();
    int m = n / 2;
    for (int i = 0; i < m; ++i) {
      swap(s[i], s[n - 1 - i]);
    }
  }
};
