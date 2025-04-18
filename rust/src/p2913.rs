use std::collections::HashSet;

fn count_unique_subsets(nums: &[i32], start: usize, end: usize) -> i32 {
    let unique_elements: HashSet<_> = nums[start..end].iter().cloned().collect();
    (unique_elements.len() * unique_elements.len()) as i32
}

impl Solution {
    pub fn sum_counts(nums: Vec<i32>) -> i32 {
        nums.iter()
            .enumerate()
            .flat_map(|(i, _)| ((i + 1)..(nums.len() + 1)).map(move |j| (i, j)))
            .map(|(i, j)| count_unique_subsets(&nums, i, j))
            .sum()
    }
}
