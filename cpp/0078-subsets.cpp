class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result(1);
        for (auto num : nums) {
            result.reserve(result.size() * 2);
            auto half = result.begin() + result.size();
            copy(result.begin(), half, back_inserter(result));
            for_each(half, result.end(), [&num](decltype(result[0]) &e) {
               e.push_back(num);
            });
        }
        return result;
    }
};
