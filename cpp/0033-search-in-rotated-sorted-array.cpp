class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1,
            first = 0,
            last = nums.size();
        while (first != last) {
            const int mid = first + (last - first)/2;
            if (nums[mid] == target) {
                res = mid;
                break;
            } else if (nums[first] <= nums[mid]) {
                if (nums[first] <= target && target < nums[mid]) {
                    last = mid;
                } else {
                    first = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[last-1]) {
                    first = mid + 1;
                } else {
                    last = mid;
                }
            }
        }
        return res;
    }
};
