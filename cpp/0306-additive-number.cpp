#include <string>

using namespace std;

class Solution {
public:
  bool isAdditiveNumber(string num) {
    auto mid = next(num.begin(), num.size() / 2);
    for (auto i = 1 + num.begin(); i <= mid; ++i)
      for (auto j = i + 1; j < num.end(); ++j)
        if (is_valid(num.begin(), i, j, num.end()))
          return true;
    return false;
  }

private:
  template <typename ForwardIt>
  bool is_valid(ForwardIt fb, ForwardIt fe, ForwardIt se, ForwardIt last) {
    if ((fb + 1 < fe && *fb == '0') || (fe + 1 < se && *fe == '0'))
      return false;
    if (se == last)
      return true;
    string s1(fb, fe);
    string s2(fe, se);
    string s3 = addStrings(s1, s2);
    ForwardIt te = next(se, s3.size());
    if (last < te)
      return false;
    string s4(se, te);
    if (s3 != s4)
      return false;
    return is_valid(fe, se, te, last);
  }

  string addStrings(const string &num1, const string &num2) {
    if (num1.empty() || num1 == "0") {
      return num2;
    } else if (num2.empty() || num2 == "0") {
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
