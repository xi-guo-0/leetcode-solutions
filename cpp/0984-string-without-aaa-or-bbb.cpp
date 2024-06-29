#include <string>

using namespace std;

class Solution {
public:
  string strWithout3a3b(int a, int b) {
    string ans(a + b, ca);
    for (int i = ans.size() - 1; 0 <= i; --i) {
      if (a < b) {
        if (ans.size() <= i + 2 || ans[i + 1] != cb || ans[i + 2] != cb) {
          ans[i] = cb;
          --b;
        } else {
          --a;
        }
      } else {
        if (ans.size() <= i + 2 || ans[i + 1] != ca || ans[i + 2] != ca) {
          --a;
        } else {
          ans[i] = cb;
          --b;
        }
      }
    }
    return ans;
  }

private:
  static char constexpr ca = 'a';
  static char constexpr cb = 'b';
};

int main() { return 0; }
