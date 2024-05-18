class Solution {
public:
    bool search(vector<int>& nums, int target) {
        bool res = false;
        int first = 0,
            last = nums.size();
        while (first != last) {
            const int mid = first + (last - first)/2;
            if (nums[mid] == target) {
                res = true;
                break;
            } else if (nums[first] < nums[mid]) {
                if (nums[first] <= target && target < nums[mid]) {
                    last = mid;
                } else {
                    first = mid + 1;
                }
            } else if (nums[first] > nums[mid]) {
                if (nums[mid] < target && target <= nums[last-1]) {
                    first = mid + 1;
                } else {
                    last = mid;
                }
            } else {
                first++;
            }
        }
        return res;        
    }
};
