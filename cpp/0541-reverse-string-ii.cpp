#include <ranges>
#include <string>

using namespace std;
namespace ranges = std::ranges;

class Solution {
public:
  string reverseStr(string s, int k) {
    auto reversed = [](const auto &str) {
      return string(str.rbegin(), str.rend());
    };

    if (s.length() <= k)
      return reversed(s);

    auto first_part = s.substr(0, k);
    auto second_part = s.substr(k, k);
    string remaining;
    ranges::copy(s | ranges::views::drop(2 * k), back_inserter(remaining));

    return reversed(first_part) + second_part + reverseStr(remaining, k);
  }
};
