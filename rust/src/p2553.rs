impl Solution {
    pub fn separate_digits(nums: Vec<i32>) -> Vec<i32> {
        nums.into_iter()
            .flat_map(|num| {
                num.to_string()
                    .chars()
                    .map(|c| c.to_digit(10).unwrap_or(0) as i32)
                    .collect::<Vec<i32>>()
            })
            .collect()
    }
}
