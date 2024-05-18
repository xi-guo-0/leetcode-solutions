class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        int result = nums[0];
        int sum = 0;
        for (const auto& n : nums) {
            sum = sum > 0 ? sum + n : n;
            result = max(result, sum);
        }
        return result;
    }
};
