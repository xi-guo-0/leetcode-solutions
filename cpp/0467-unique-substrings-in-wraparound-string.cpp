#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int findSubstringInWraproundString(string s) {
    vector<int> dp(26, 0);

    int length = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (i > 0 && (s[i] == s[i - 1] + 1 || (s[i] == 'a' && s[i - 1] == 'z'))) {
        ++length;
      } else {
        length = 1;
      }
      dp[s[i] - 'a'] = max(dp[s[i] - 'a'], length);
    }

    int result = 0;
    for (int len : dp) {
      result += len;
    }

    return result;
  }
};
