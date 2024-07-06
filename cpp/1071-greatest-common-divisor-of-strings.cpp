#include <string>

using namespace std;

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    if (str1.size() == 0 || str2.size() == 0) {
      return "";
    }
    int n = str2.size();
    int p = 0;
    while (str1.substr(p, n) == str2)
      p += n;
    if (p == str1.size())
      return str2;
    if (p + n <= str1.size())
      return "";
    return gcdOfStrings(str2, str1.substr(p));
  }
};

int main() { return 0; }
