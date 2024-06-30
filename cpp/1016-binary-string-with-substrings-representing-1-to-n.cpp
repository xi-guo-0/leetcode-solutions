#include <bitset>
#include <string>

using namespace std;

class Solution {
public:
  bool queryString(string s, int n) {
    for (int i = n; 0 < i; i--) {
      const string bs = bitset<8 * sizeof(int)>(i).to_string();
      const string l = bs.substr(bs.find('1'));
      if (s.find(l) == string::npos)
        return false;
    }
    return true;
  }
};

int main() { return 0; }
