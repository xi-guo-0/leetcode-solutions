#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int shipWithinDays(vector<int> &weights, int days) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (canShipWithCapacity(weights, days, mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }

  bool canShipWithCapacity(const vector<int> &weights, int days, int capacity) {
    int daysRequired = 1;
    int currentLoad = 0;
    for (const auto &weight : weights) {
      if (currentLoad + weight > capacity) {
        daysRequired += 1;
        currentLoad = 0;
      }
      currentLoad += weight;
    }
    return daysRequired <= days;
  }
};

int main() { return 0; }
