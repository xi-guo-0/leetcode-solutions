#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int len1 = s1.size(), len2 = s2.size();
    unordered_map<int, pair<int, int>> mp;
    int cnt1 = 0, cnt2 = 0, idx = 0;
    while (cnt1 < n1) {
      for (int i = 0; i < len1; ++i) {
        if (s1[i] == s2[idx]) {
          if (++idx == len2) {
            ++cnt2;
            idx = 0;
          }
        }
      }
      ++cnt1;
      if (mp.find(idx) != mp.end()) {
        auto &[c1, c2] = mp[idx];
        int cycle1 = cnt1 - c1, cycle2 = cnt2 - c2;
        cnt2 += (n1 - cnt1) / cycle1 * cycle2;
        cnt1 += (n1 - cnt1) / cycle1 * cycle1;
      } else {
        mp[idx] = {cnt1, cnt2};
      }
    }
    return cnt2 / n2;
  }
};
