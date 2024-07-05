#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int longestStrChain(vector<string> &words) {
    sort(words.begin(), words.end(), [](const auto &a, const auto &b) {
      return a.size() != b.size() ? a.size() < b.size() : a < b;
    });
    unordered_map<string, int> dp;
    int ans = 0;
    for (const auto &w : words) {
      for (int i = 0; i < w.size(); ++i) {
        auto pre = w.substr(0, i) + w.substr(i + 1);
        int v = dp.count(pre) ? dp[pre] + 1 : 1;
        dp[w] = max(dp[w], v);
      }
      ans = max(ans, dp[w]);
    }
    return ans;
  }
};

int main() { return 0; }