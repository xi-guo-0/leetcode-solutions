class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        dfs(candidates, path, result, target, 0);
        return result;
    }
    
private:
    void dfs(vector<int>& nums, vector<int>& path, vector<vector<int>>& result, int gap, int start) {
        if (gap == 0) {
            result.push_back(path);
            return;
        }
        for (size_t i = start; i < nums.size(); i++) {
            if (gap < nums[i]) return;
            path.push_back(nums[i]);
            dfs(nums, path, result, gap - nums[i], i);
            path.pop_back();
        }
    }
};
