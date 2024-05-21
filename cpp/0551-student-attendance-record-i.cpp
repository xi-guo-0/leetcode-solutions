#include <string>

class Solution {
public:
  bool checkRecord(std::string s) {
    int countA = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'A') {
        countA++;
      }
      if (countA > 1) {
        return false;
      }
      if (s[i] == 'L') {
        if (i + 1 < s.length() && s[i + 1] == 'L') {
          if (i + 2 < s.length() && s[i + 2] == 'L') {
            return false;
          }
        }
      }
    }
    return true;
  }
};
