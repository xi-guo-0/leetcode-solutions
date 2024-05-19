class Solution {
public:
  string addStrings(const string &num1, const string &num2) {
    if (num1.size() == 0 || num1 == "0") {
      return num2;
    } else if (num2.size() == 0 || num2 == "0") {
      return num1;
    }
    const int m = num1.size();
    const int n = num2.size();
    int k = max(m, n);
    int c = 0;
    string s(1 + k, '0');
    for (int i = m - 1, j = n - 1; 0 <= i || 0 <= j; i--, j--, k--) {
      const int a = 0 <= i ? num1[i] - '0' : 0;
      const int b = 0 <= j ? num2[j] - '0' : 0;
      s[k] += (a + b + c) % 10;
      c = (a + b + c) / 10;
    }
    s[k] += c;
    return s[0] == '0' ? s.substr(s.find_first_not_of('0')) : s;
  }
};
