#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    int ans = 0;
    int mx = values[0];
    for (int j = 1; j < values.size(); ++j) {
      ans = max(ans, mx + values[j] - j);
      mx = max(mx, values[j] + j);
    }
    return ans;
  }
};

int main() { return 0; }
