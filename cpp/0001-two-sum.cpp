#include <cassert>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> res;
    unordered_map<int, int> mapping;
    for (int i = 0; i < nums.size(); i++)
      mapping[nums[i]] = i;
    for (int i = 0; i < nums.size(); i++) {
      const int gap = target - nums[i];
      if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
        res.push_back(i);
        res.push_back(mapping[gap]);
      }
    }
    return res;
  }
};

int main() {
  vector<int> nums{2, 7, 11, 15};
  int target = 9;
  vector<int> ans{0, 1};
  assert(Solution().twoSum(nums, target) == ans);
  return 0;
}
