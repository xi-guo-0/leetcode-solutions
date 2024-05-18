class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result(1);
        
        size_t previous_size = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            const size_t size = result.size();
            for (size_t j = 0; j < size; j++) {
                if (i == 0 || nums[i] != nums[i - 1] || j >= previous_size) {
                    result.push_back(result[j]);
                    result.back().push_back(nums[i]);
                }
            }
            previous_size = size;
        }
        return result;
    }
};
