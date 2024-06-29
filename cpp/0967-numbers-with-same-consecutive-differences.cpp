#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> numsSameConsecDiff(int n, int k) {
    vector<int> results;
    if (n == 1) {
      for (int i = 0; i <= 9; ++i) {
        results.push_back(i);
      }
      return results;
    }
    for (int num = 1; num <= 9; ++num) {
      dfs(n - 1, num, k, results);
    }
    return results;
  }

private:
  void dfs(int n, int current, int k, vector<int> &results) {
    if (n == 0) {
      results.push_back(current);
      return;
    }
    int last_digit = current % 10;
    if (last_digit + k <= 9) {
      dfs(n - 1, current * 10 + last_digit + k, k, results);
    }
    if (k != 0 && last_digit - k >= 0) {
      dfs(n - 1, current * 10 + last_digit - k, k, results);
    }
  }
};

int main() { return 0; }
