class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        int min_gap = INT_MAX;
        sort(nums.begin(), nums.end());
        for (auto a = nums.begin(); a != prev(nums.end(), 2); a++) {
            auto b = next(a);
            auto c = prev(nums.end());
            while (b < c) {
                const int sum = *a + *b + *c;
                const int gap = abs(sum - target);
                if (min_gap > gap) {
                    min_gap = gap;
                    result = sum;
                }
                if (gap == 0) {
                    break;
                }
            if (sum < target) b++;
            else c--;                
            }
        }
        return result;
    }
};
