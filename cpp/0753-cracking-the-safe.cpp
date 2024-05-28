/**
 * https://en.wikipedia.org/wiki/De_Bruijn_sequence
 */
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void dfs(string &result, unordered_set<string> &visited, int n, int k,
         const string &start) {
  for (char i = '0'; i < '0' + k; ++i) {
    string next = start + i;
    if (visited.find(next) == visited.end()) {
      visited.insert(next);
      dfs(result, visited, n, k, next.substr(1));
      result += i;
    }
  }
}

class Solution {
public:
  string crackSafe(int n, int k) {
    if (n == 1 && k == 1)
      return "0";
    string result;
    unordered_set<string> visited;
    string start(n - 1, '0');
    dfs(result, visited, n, k, start);
    result += start;
    return result;
  }
};

int main() {
  int n = 3;
  int k = 3;

  Solution solution;
  string result = solution.crackSafe(n, k);
  cout << result << endl;

  return 0;
}
