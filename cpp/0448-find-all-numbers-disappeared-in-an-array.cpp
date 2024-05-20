#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    vector<int> result;
    int temp;
    for (int i = 0; i < nums.size(); i++) {
      while (nums[i] != nums[nums[i] - 1]) {
        temp = nums[nums[i] - 1];
        nums[nums[i] - 1] = nums[i];
        nums[i] = temp;
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        result.push_back(i + 1);
      }
    }
    return result;
  }
};
