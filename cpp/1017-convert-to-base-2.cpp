#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
  string baseNeg2(int n) {
    if (n == 0) {
      return "0";
    }
    ostringstream os;
    while (n != 0) {
      int a = abs(n % (-2));
      os << (char)(a + '0');
      n = (n - a) / (-2);
    }
    string s(os.str());
    reverse(s.begin(), s.end());
    return s;
  }
};

int main() { return 0; }
