#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubstring(string s, int k) {
    int n = s.length();
    if (n == 0 || k > n)
      return 0;

    vector<int> count(26, 0);
    for (char c : s)
      count[c - 'a']++;

    int l = 0, r = 0;
    int maxLen = 0;

    while (r < n) {
      if (count[s[r] - 'a'] < k) {
        maxLen = max(maxLen, longestSubstring(s.substr(l, r - l), k));
        l = r + 1;
      }
      r++;
    }

    if (l == 0)
      return n;

    maxLen = max(maxLen, longestSubstring(s.substr(l, r - l), k));

    return maxLen;
  }
};
