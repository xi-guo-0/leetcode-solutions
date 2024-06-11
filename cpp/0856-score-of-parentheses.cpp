#include <string>

using namespace std;

class Solution {
public:
  int scoreOfParentheses(const string &S) {
    int result = 0;
    int layer = 0;
    char last_ch = '\0';
    for (const char ch : S) {
      if (ch == '(') {
        layer++;
      } else {
        layer--;
        if (last_ch == '(') {
          result += (1 << layer);
        }
      }
      last_ch = ch;
    }
    return result;
  }
};

int main() { return 0; }
