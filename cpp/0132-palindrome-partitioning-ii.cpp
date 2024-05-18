#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(const string &s, int i, int j) {
  while (i < j) {
    if (s[i] != s[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

class Solution {
public:
  int minCut(string s) {

    int n = s.length();

    vector<int> dp(n, n);

    dp[0] = 0;

    for (int i = 1; i < n; ++i) {
      if (isPalindrome(s, 0, i)) {
        dp[i] = 0;
        continue;
      }

      for (int j = 0; j < i; ++j) {
        if (isPalindrome(s, j + 1, i)) {
          dp[i] = min(dp[i], dp[j] + 1);
        }
      }
    }

    return dp[n - 1];
  }
};

int main() {
  string s;
  cout << "Enter a string: ";
  getline(cin, s);

  int minCuts = Solution().minCut(s);
  cout << "Minimum number of cuts needed for palindromization: " << minCuts
       << endl;

  return 0;
}
