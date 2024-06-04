#include <cmath>
#include <functional>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
  double soupServings(int n) {
    if (n >= 5000)
      return 1.0;

    unordered_map<int, unordered_map<int, double>> memo;

    auto dfs = [&](auto &dfs, int a, int b) -> double {
      if (a <= 0 && b <= 0)
        return 0.5;
      if (a <= 0)
        return 1.0;
      if (b <= 0)
        return 0.0;
      if (memo[a][b])
        return memo[a][b];
      return memo[a][b] =
                 0.25 * (dfs(dfs, a - 100, b) + dfs(dfs, a - 75, b - 25) +
                         dfs(dfs, a - 50, b - 50) + dfs(dfs, a - 25, b - 75));
    };

    return dfs(dfs, n, n);
  }
};

int main() { return 0; }
