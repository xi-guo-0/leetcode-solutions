#include <string>

using namespace std;

class Solution {
public:
  string decodeAtIndex(string s, int k) {
    long sz = 0;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
      if (isdigit(s[i])) {
        sz *= (s[i] - '0');
      } else {
        ++sz;
      }
    }

    for (int i = n - 1; 0 <= i; --i) {
      k %= sz;
      if (k == 0 && isalpha(s[i])) {
        return string(1, s[i]);
      }
      if (isdigit(s[i])) {
        sz /= (s[i] - '0');
      } else {
        --sz;
      }
    }
    return {};
  }
};

int main() { return 0; }
