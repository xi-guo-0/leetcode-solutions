#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
  string removeOuterParentheses(string s) {
    ostringstream os;
    for (int i = 0; i < s.size();) {
      int j = i + 1;
      int cnt = 1;
      for (; j < s.size() && cnt; j++) {
        if (s[j] == '(')
          cnt++;
        else
          cnt--;
      }
      os << s.substr(i + 1, j - i - 2);
      i = j;
    }
    return os.str();
  }
};

int main() { return 0; }
