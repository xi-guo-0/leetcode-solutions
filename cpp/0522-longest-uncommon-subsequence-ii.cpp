#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool isSubsequence(const string &s, const string &t) {
  int i = 0;
  for (char c : t) {
    if (i < s.size() && s[i] == c)
      ++i;
  }
  return i == s.size();
}
class Solution {
public:
  int findLUSlength(vector<string> &strs) {
    unordered_set<string> seen, duplicates;
    for (const string &s : strs) {
      if (!seen.insert(s).second)
        duplicates.insert(s);
    }
    int longest = -1;
    for (const string &s : seen) {
      if (!duplicates.count(s)) {
        bool uncommon = true;
        for (const string &t : seen) {
          if (s != t && isSubsequence(s, t)) {
            uncommon = false;
            break;
          }
        }
        if (uncommon)
          longest = max(longest, (int)s.size());
      }
    }
    return longest;
  }
};
