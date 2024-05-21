#include <vector>

class Solution {
public:
  int countArrangement(int N) {
    std::vector<bool> visited(N + 1, false);
    n = N;
    return helper(visited, 1);
  }

private:
  int helper(std::vector<bool> &visited, int pos) {
    if (n < pos) {
      return 1;
    } else {
      int ans = 0;
      for (int i = 1; i <= n; ++i) {
        if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
          visited[i] = true;
          ans += helper(visited, pos + 1);
          visited[i] = false;
        }
      }
      return ans;
    }
  }

  int n;
};
