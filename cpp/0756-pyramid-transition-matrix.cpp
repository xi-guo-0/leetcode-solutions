#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool pyramidTransition(const string &bottom, const vector<string> &allowed) {
    unordered_map<string, set<char>> m;
    for (const auto &rule : allowed)
      m[rule.substr(0, 2)].insert(rule[2]);

    unordered_map<string, bool> memo;
    return dfs(bottom, "", m, 0, memo);
  }

private:
  bool dfs(const string &curr, const string &next,
           unordered_map<string, set<char>> &m, int i,
           unordered_map<string, bool> &memo) {
    if (curr.length() == 1)
      return true;

    if (curr.length() == next.length() + 1)
      return dfs(next, "", m, 0, memo);

    string key = curr + next;
    if (memo.find(key) != memo.end())
      return memo[key];

    for (const char &c : m[curr.substr(i, 2)]) {
      if (dfs(curr, next + c, m, i + 1, memo)) {
        memo[key] = true;
        return true;
      }
    }

    memo[key] = false;
    return false;
  }
};

int main() { return 0; }
