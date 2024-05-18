class Solution {
public:
  int titleToNumber(const string &s) {
    int sum = 0;
    for (const auto ch : s)
      sum = 26 * sum - 'A' + 1 + toupper(ch);
    return sum;
  }
};
