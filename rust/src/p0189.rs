impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let K = k as usize % nums.len();
        let a = nums[0];
        Self::reverse_in_place(nums, 0, nums.len());
        Self::reverse_in_place(nums, 0, K);
        Self::reverse_in_place(nums, K, nums.len());
    }

    fn reverse_in_place(nums: &mut Vec<i32>, l: usize, r: usize) {
        for i in 0..((r - l) / 2) {
            let t = nums[l + i];
            nums[l + i] = nums[r - i - 1];
            nums[r - i - 1] = t;
        }
    }
}
