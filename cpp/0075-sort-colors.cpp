class Solution {
public:
    void sortColors(vector<int>& nums) {
        partition(partition(nums.begin(),
                            nums.end(),
                            bind1st(equal_to<int>(), 0)),
                  nums.end(),
                  bind1st(equal_to<int>(), 1));
    }
};
