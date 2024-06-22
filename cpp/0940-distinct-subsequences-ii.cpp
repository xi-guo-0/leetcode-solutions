#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int distinctSubseqII(string s) {
    const int MOD = 1'000'000'007;
    int n = s.size();
    vector<int> dp(n + 1);

    unordered_map<char, int> last_occurrence;
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
      dp[i] = (2 * dp[i - 1]) % MOD;
      if (last_occurrence.find(s[i - 1]) != last_occurrence.end()) {
        int j = last_occurrence[s[i - 1]];
        dp[i] = (dp[i] - dp[j - 1] + MOD) % MOD;
      }
      last_occurrence[s[i - 1]] = i;
    }

    return (dp[n] - 1 + MOD) % MOD;
  }
};

int main() { return 0; }
