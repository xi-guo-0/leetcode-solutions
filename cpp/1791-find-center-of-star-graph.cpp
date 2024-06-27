#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int findCenter(vector<vector<int>> &edges) {
    const auto &a = edges[0];
    const auto &b = edges[1];
    vector<int> ps{a[0], a[1], b[0], b[1]};
    sort(ps.begin(), ps.end());
    for (int i = 1; i < ps.size(); ++i) {
      if (ps[i - 1] == ps[i]) {
        return ps[i];
      }
    }
    return -1;
  }
};

int main() { return 0; }
