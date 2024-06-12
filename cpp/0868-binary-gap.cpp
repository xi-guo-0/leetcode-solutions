#include <algorithm>
#include <bitset>

using namespace std;

class Solution {
public:
  int binaryGap(int n) {
    const int sz = sizeof(int) * 8;
    bitset<sz> bits(n);
    int result = 0;
    if (bits.count() > 1) {
      string s(std::move(bits.to_string()));
      auto i = s.find_first_of('1');
      auto j = s.find_first_of('1', i + 1);
      while (j < s.size()) {
        int tmp = j - i;
        result = max(result, tmp);
        i = j;
        j = s.find_first_of('1', i + 1);
      }
    }
    return result;
  }
};

int main() { return 0; }
