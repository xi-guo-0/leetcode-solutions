#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    ranges::sort(points, [](const vector<int> &a, const vector<int> &b) {
      return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
    });
    while (points.size() > k)
      points.pop_back();
    return points;
  }
};

int main() { return 0; }
