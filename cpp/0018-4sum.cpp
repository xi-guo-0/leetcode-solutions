class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        
        unordered_multimap<int, pair<int, int>> cache;
        for (int i = 0; i + 1 < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                cache.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));
        for (auto i = cache.begin(); i != cache.end(); i++) {
            int x = target - i->first;
            auto range = cache.equal_range(x);
            for (auto j = range.first; j != range.second; j++) {
                auto a = i->second.first;
                auto b = i->second.second;
                auto c = j->second.first;
                auto d = j->second.second;
                if (a != c && a != d && b != c && b != d) {
                    vector<int> vec = {nums[a], nums[b], nums[c], nums[d]};
                    sort(vec.begin(), vec.end());
                    result.push_back(vec);
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
        
    }
};
