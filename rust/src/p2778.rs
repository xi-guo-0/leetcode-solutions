impl Solution {
    pub fn sum_of_squares(nums: Vec<i32>) -> i32 {
        nums.iter()
            .enumerate()
            .map(|(i, v)| if nums.len() % (i + 1) == 0 { v * v } else { 0 })
            .sum()
    }
}
