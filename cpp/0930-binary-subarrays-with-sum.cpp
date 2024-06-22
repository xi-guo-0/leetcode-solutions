#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int numSubarraysWithSum(vector<int> &nums, int goal) {
    int n = nums.size();
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;

    int sum = 0;
    int count = 0;

    for (int i = 0; i < n; ++i) {
      sum += nums[i];

      if (prefixCount.find(sum - goal) != prefixCount.end()) {
        count += prefixCount[sum - goal];
      }

      prefixCount[sum]++;
    }

    return count;
  }
};

int main() { return 0; }
