#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int findJudge(int n, vector<vector<int>> &trust) {
    if (n == 1) {
      return 1;
    }
    vector<int> in_out(n + 1);
    for (const auto t : trust)
      --in_out[t[0]], ++in_out[t[1]];
    auto it = find(in_out.begin(), in_out.end(), n - 1);
    return it != in_out.end() ? distance(in_out.begin(), it) : -1;
  }
};

int main() { return 0; }
