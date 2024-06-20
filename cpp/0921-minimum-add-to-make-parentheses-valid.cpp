#include <string>

using namespace std;

class Solution {
public:
  int minAddToMakeValid(const string &s) {
    int cnt = 0, result = 0;
    for (const char ch : s)
      if (ch == '(')
        cnt++;
      else if (cnt == 0)
        result++;
      else
        cnt--;
    return result + cnt;
  }
};

int main() { return 0; }
