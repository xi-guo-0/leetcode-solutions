#include <string>

using namespace std;

class Solution {
public:
  int minFlipsMonoIncr(string const &S) {
    int dp0 = 0;
    int dp1 = 0;
    for (char const ch : S) {
      if (ch == '0') {
        dp1 = min(dp0 + 1, dp1 + 1);
      } else {
        dp1 = min(dp0, dp1);
        dp0 = dp0 + 1;
      }
    }
    return min(dp0, dp1);
  }
};

int main() { return 0; }
