impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut presum = vec![1; n];
        let mut sufsum = vec![1; n];
        for i in 1..presum.len() {
            presum[i] = presum[i - 1] * nums[i - 1];
        }
        for i in (0..presum.len() - 1).rev() {
            sufsum[i] = nums[i + 1] * sufsum[i + 1];
        }
        presum
            .into_iter()
            .zip(sufsum.into_iter())
            .map(|(a, b)| a * b)
            .collect()
    }
}
