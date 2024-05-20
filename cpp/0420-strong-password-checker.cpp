#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int strongPasswordChecker(string password) {
    using ranges::any_of;
    const auto &s = password;
    int missing_type =
        3 - any_of(s, ::islower) - any_of(s, ::isupper) - any_of(s, ::isdigit);
    int change = 0;
    int one = 0;
    int two = 0;
    int p = 2;

    while (p < s.size()) {
      if (s[p] == s[p - 1] && s[p] == s[p - 2]) {
        int length = 2;
        while (p < s.size() && s[p] == s[p - 1]) {
          length += 1;
          p += 1;
        }
        change += length / 3;
        if (length % 3 == 0) {
          one += 1;
        } else if (length % 3 == 1) {
          two += 1;
        }
      } else {
        p += 1;
      }
    }
    if (s.size() < 6) {
      return max(missing_type, 6 - static_cast<int>(s.size()));
    } else if (s.size() <= 20) {
      return max(missing_type, change);
    } else {
      int deletion = s.size() - 20;

      change -= min(deletion, one);
      change -= min(max(deletion - one, 0), two * 2) / 2;
      change -= max(deletion - one - 2 * two, 0) / 3;
      return deletion + max(missing_type, change);
    }
  }
};

int main() {
  Solution solution;
  assert((solution.strongPasswordChecker("a") == 5));
  assert((solution.strongPasswordChecker("aA1") == 3));
  assert((solution.strongPasswordChecker("1337C0d3") == 0));
  assert((solution.strongPasswordChecker("bbaaaaaaaaaaaaaaacccccc") == 8));
  return 0;
}
