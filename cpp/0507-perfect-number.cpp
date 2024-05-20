class Solution {
public:
  bool checkPerfectNumber(int num) {
    vector<int> nums{6, 28, 496, 8128, 33550336};
    return nums.end() != find(nums.begin(), nums.end(), num);
  }
};
