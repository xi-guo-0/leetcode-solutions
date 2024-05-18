class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) return result;
        sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        return result;
    }
    
    template<typename IT>
    bool next_permutation(IT first, IT last) {
        const auto rfirst = reverse_iterator<IT>(last);
        const auto rlast = reverse_iterator<IT>(first);
        
        auto pivot = next(rfirst);
        
        while (pivot != rlast && *pivot >= *prev(pivot))
            pivot++;
        
        if (pivot == rlast) {
            reverse(rfirst, rlast);
            return false;
        }
        
        auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
        
        swap(*change, *pivot);
        reverse(rfirst, pivot);
        
        return true;
    }
};
