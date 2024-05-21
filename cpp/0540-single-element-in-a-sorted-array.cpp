class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    return accumulate(begin(nums), end(nums), 0, bit_xor<int>());
  }
};
