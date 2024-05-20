#include <string>

class Solution {
public:
  bool detectCapitalUse(std::string word) {
    if (word.length() < 2) {
      return true;
    }
    const char *chars = word.c_str();
    if (islower(chars[0])) {
      for (int i = 1; i < word.length(); i++) {
        if (isupper(chars[i])) {
          return false;
        }
      }
    } else {
      if (islower(chars[1])) {
        for (int i = 2; i < word.length(); i++) {
          if (isupper(chars[i])) {
            return false;
          }
        }
      } else {
        for (int i = 2; i < word.length(); i++) {
          if (islower(chars[i])) {
            return false;
          }
        }
      }
    }
    return true;
  }
};
