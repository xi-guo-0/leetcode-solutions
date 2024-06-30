#include <vector>

using namespace std;

class Solution {
public:
  int twoCitySchedCost(vector<vector<int>> &costs) {
    sort(costs.begin(), costs.end(), comp);
    int result = 0;
    int len = costs.size();
    for (int i = 0; i < len / 2; i++) {
      result += (costs[i][0] + costs[len - i - 1][1]);
    }
    return result;
  }

private:
  static int diff(const vector<int> &x) { return x[1] - x[0]; }
  static bool comp(const vector<int> &lhs, const vector<int> &rhs) {
    return diff(lhs) > diff(rhs);
  }
};

int main() { return 0; }
