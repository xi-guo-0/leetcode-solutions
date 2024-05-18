class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); ) {
            int j = i + 1;
            while (j < nums.size() && nums[i] == nums[j]) j++;
            if (1 == j - i) { nums[k++] = nums[i]; }
            else if (2 <= j - i) { nums[k++] = nums[k++] = nums[i]; }
            i = j;
        }
        return k;
    }
};
