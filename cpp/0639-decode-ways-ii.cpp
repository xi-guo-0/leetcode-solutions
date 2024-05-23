#include <string>
#include <vector>

using namespace std;

constexpr int64_t MOD = 1000000007;

template <typename T>
concept Integer = std::is_integral_v<T>;

template <Integer T, Integer U> int modAdd(T a, U b) { return (a + b) % MOD; }

template <Integer T, Integer U> int modMul(T a, U b) { return (a * b) % MOD; }

template <typename T, typename... Args> int modAdd(T first, Args... args) {
  return modAdd(first, modAdd(args...));
}

template <typename T, typename... Args> int modMul(T first, Args... args) {
  return modMul(first, modMul(args...));
}

class Solution {
public:
  int numDecodings(string s) {
    int64_t dp[100001] = {1, (s[0] == '*') ? 9 : (s[0] == '0') ? 0 : 1};

    for (int i = 2; i <= s.size(); ++i) {
      if (s[i - 1] == '*') {
        dp[i] = modMul(9, dp[i - 1]);
        if (s[i - 2] == '1') {
          dp[i] = modAdd(dp[i], modMul(9, dp[i - 2]));
        } else if (s[i - 2] == '2') {
          dp[i] = modAdd(dp[i], modMul(6, dp[i - 2]));
        } else if (s[i - 2] == '*') {
          dp[i] = modAdd(dp[i], modMul(15, dp[i - 2]));
        }
      } else {
        dp[i] = (s[i - 1] != '0') ? dp[i - 1] : 0;
        if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
          dp[i] = modAdd(dp[i], dp[i - 2]);
        } else if (s[i - 2] == '*') {
          dp[i] = modAdd(dp[i], modMul((s[i - 1] <= '6' ? 2 : 1), dp[i - 2]));
        }
      }
    }

    return dp[s.size()];
  }
};

int main() { return 0; }
