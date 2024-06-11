#include <algorithm>
#include <limits>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
    size_t n = quality.size();
    if (k == 1) {
      return *min_element(wage.begin(), wage.end());
    }

    vector<size_t> ids(n);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](size_t a, size_t b) {
      return wage[a] * quality[b] < wage[b] * quality[a];
    });

    double res = numeric_limits<double>::max();
    priority_queue<int> heap;
    int sum = 0;
    for (size_t i = 0; i < k - 1; ++i) {
      heap.push(quality[ids[i]]);
      sum += quality[ids[i]];
    }
    for (size_t i = k - 1; i < n; ++i) {
      size_t idx = ids[i];
      double scale = static_cast<double>(wage[idx]) / quality[idx];

      double tmp = (sum + quality[idx]) * scale;
      if (tmp < res) {
        res = tmp;
      }

      if (quality[idx] < heap.top()) {
        sum -= heap.top();
        heap.pop();
        sum += quality[idx];
        heap.push(quality[idx]);
      }
    }
    return res;
  }
};

int main() { return 0; }
