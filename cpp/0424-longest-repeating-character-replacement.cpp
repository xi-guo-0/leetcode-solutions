#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int characterReplacement(std::string s, int k) {
    if (s.empty()) {
      return 0;
    }

    std::vector<int> cnt(26, 0);
    int left = 0;
    int right = 0;
    int charMax = 0;

    for (right = 0; right < s.length(); ++right) {
      int i = s[right] - 'A';
      cnt[i]++;
      charMax = std::max(charMax, cnt[i]);
      if (charMax + k < right - left + 1) {
        cnt[s[left] - 'A']--;
        left++;
      }
    }
    return s.length() - left;
  }
};
