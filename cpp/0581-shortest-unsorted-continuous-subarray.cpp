class Solution {
public:
  int findUnsortedSubarray(const vector<int> &nums) {
    vector<int> m(nums.begin(), nums.end());
    sort(m.begin(), m.end());
    int i = 0, j = nums.size() - 1;
    while (i < m.size() && m[i] == nums[i])
      i++;
    while (0 <= j && m[j] == nums[j])
      j--;
    return j > i ? j - i + 1 : 0;
  }
};
