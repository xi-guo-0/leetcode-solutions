#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int calculate(string s) {
    std::string::const_iterator it = s.begin();
    return calc(it, s.end());
  }

private:
  int calc(std::string::const_iterator &chars,
           std::string::const_iterator end) {
    int ans = 0;
    int curr = 0;
    int sig = 1;
    bool has_num = false;

    for (;;) {
      char ch = chars != end ? *chars : ')';
      if (chars != end) {
        ++chars;
      }
      if (isdigit(ch)) {
        curr = curr * 10 - '0' + ch;
        has_num = true;
      } else {
        if (has_num) {
          ans += curr * sig;
          curr = 0;
          sig = 1;
          has_num = false;
        }
        switch (ch) {
        case '(':
          ans += calc(chars, end) * sig;
          sig = 1;
          break;
        case ')':
          std::cout << ans << std::endl;
          return ans;
        case '-':
          sig = -sig;
          break;
        default:
          break;
        }
      }
    }
    return ans;
  }
};

int main() {
  std::cout << Solution().calculate("(1+(4+5+2)-3)+(6+8)") << std::endl;
  return 0;
}
