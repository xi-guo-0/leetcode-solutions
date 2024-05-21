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
  string findLongestWord(string s, vector<string> &dictionary) {
    string ans;
    for (const auto &w : dictionary) {
      if ((ans.size() < w.size() || (ans.size()==w.size() && w < ans)) && isSubsequence(w, s)) {
        ans = w;
      }
    }
    return ans;
  }
};
