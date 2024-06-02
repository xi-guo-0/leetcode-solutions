#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int bestRotation(vector<int> &nums) {
    int n = nums.size();
    vector<int> change(n, 0);

    for (int i = 0; i < n; ++i) {
      int lower = (i - nums[i] + 1 + n) % n;
      int upper = (i + 1) % n;

      change[lower]--;
      change[upper]++;

      if (lower > upper) {
        change[0]--;
      }
    }

    int bestIndex = 0, maxScore = -n, score = 0;
    for (int i = 0; i < n; ++i) {
      score += change[i];
      if (score > maxScore) {
        maxScore = score;
        bestIndex = i;
      }
    }

    return bestIndex;
  }
};

int main() {
  vector<int> nums{2, 3, 1, 4, 0};
  Solution solution;
  solution.bestRotation(nums);
  return 0;
}
