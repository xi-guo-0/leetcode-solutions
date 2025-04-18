use std::collections::HashSet;

fn distinct_count(nums: &[i32]) -> i32 {
    HashSet::<&i32>::from_iter(nums).len() as i32
}

impl Solution {
    pub fn distinct_difference_array(nums: Vec<i32>) -> Vec<i32> {
        (0..nums.len())
            .map(|i| distinct_count(&nums[0..(i + 1)]) - distinct_count(&nums[(i + 1)..nums.len()]))
            .collect()
    }
}
