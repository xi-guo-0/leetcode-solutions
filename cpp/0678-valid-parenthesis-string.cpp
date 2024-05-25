#include <string>
#include <vector>

class Solution {
public:
  static bool checkValidString(const std::string &s) {
    int l = 0;
    int r = 0;
    std::vector<char> s_vec(s.begin(), s.end());
    for (size_t i = 0; i < s_vec.size(); ++i) {
      switch (s_vec[i]) {
      case ')':
        --l;
        break;
      default:
        ++l;
        break;
      }
      switch (s_vec[s_vec.size() - 1 - i]) {
      case '(':
        --r;
        break;
      default:
        ++r;
        break;
      }
      if (l < 0 || r < 0) {
        return false;
      }
    }
    return true;
  }
};
