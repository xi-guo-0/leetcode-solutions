#include <string>

class Solution {
public:
  int countBinarySubstrings(std::string s) {
    int count = 0;
    int prevCount = 0;
    int currCount = 1;

    for (int i = 1; i < s.length(); ++i) {
      if (s[i] == s[i - 1]) {
        currCount++;
      } else {
        count += std::min(prevCount, currCount);
        prevCount = currCount;
        currCount = 1;
      }
    }

    count += std::min(prevCount, currCount);

    return count;
  }
};
