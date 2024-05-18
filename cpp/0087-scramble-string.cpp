#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isScramble(string s1, string s2) {
    memset(dp, 0xff, sizeof dp);
    return solve(s1, s2, 0, 0, s1.size());
  }

private:
  bool solve(string &s1, string &s2, size_t l1, size_t l2, size_t len) {
    if (len == 0) {
      dp[l1][l2][len] = true;
      return dp[l1][l2][len];
    }
    if (dp[l1][l2][len] != -1) {
      return dp[l1][l2][len];
    }
    for (int i = l1, j = l2; i <= len + l1; i++, j++) {
      if (i == l1 + len) {
        dp[l1][l2][len] = true;
        return dp[l1][l2][len];
      }
      if (s1[i] != s2[j]) {
        break;
      }
    }
    vector<int> v(26, 0);
    for (int i = l1, j = l2; i < len + l1; i++, j++) {
      v[s1[i] - 'a']++;
      v[s2[j] - 'a']--;
    }
    for (auto x : v) {
      if (x) {
        dp[l1][l2][len] = false;
        return dp[l1][l2][len];
      }
    }
    for (int i = 1; i < len; i++) {
      if (solve(s1, s2, l1, l2, i) && solve(s1, s2, l1 + i, l2 + i, len - i)) {
        dp[l1][l2][len] = true;
        return dp[l1][l2][len];
      }

      if (solve(s1, s2, l1 + i, l2, len - i) &&
          solve(s1, s2, l1, l2 + (len - i), i)) {
        dp[l1][l2][len] = true;
        return dp[l1][l2][len];
      }
    }
    dp[l1][l2][len] = false;
    return dp[l1][l2][len];
  }

  int dp[32][32][32];
};

int main() {}
