impl Solution {
    pub fn has_trailing_zeros(nums: Vec<i32>) -> bool {
        2 <= nums.into_iter().filter(|n| n % 2 == 0).count()
    }
}
