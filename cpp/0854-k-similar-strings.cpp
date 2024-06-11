#include <string>
#include <unordered_map>

using namespace std;

int dfs(string s1, string s2, unordered_map<string, int> &memo) {
  if (s1 == s2)
    return 0;
  if (memo.count(s1) && memo[s1] != -1)
    return memo[s1];

  int n = s1.size();
  int ans = -1;
  int i = 0;
  while (i < n && s1[i] == s2[i])
    ++i;

  for (int j = i + 1; j < n; ++j) {
    if (s1[j] == s2[j] || s1[j] != s2[i])
      continue;
    swap(s1[i], s1[j]);
    int cost = dfs(s1, s2, memo);
    if (cost != -1 && (ans == -1 || 1 + cost < ans))
      ans = 1 + cost;
    swap(s1[i], s1[j]);
  }

  memo[s1] = ans;
  return ans;
}

class Solution {
public:
  int kSimilarity(string s1, string s2) {
    unordered_map<string, int> memo;
    return dfs(std::move(s1), std::move(s2), memo);
  }
};

int main() { return 0; }
