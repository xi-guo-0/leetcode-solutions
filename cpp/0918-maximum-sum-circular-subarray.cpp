#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubarraySumCircular(vector<int> &nums) {
    int total_sum = 0;
    int max_sum = numeric_limits<int>::min();
    int min_sum = numeric_limits<int>::max();
    int current_max = 0;
    int current_min = 0;

    for (int num : nums) {
      total_sum += num;
      current_max = max(current_max + num, num);
      max_sum = max(max_sum, current_max);

      current_min = min(current_min + num, num);
      min_sum = min(min_sum, current_min);
    }

    if (max_sum <= 0) {
      return max_sum;
    }

    return max(max_sum, total_sum - min_sum);
  }
};

int main() { return 0; }
