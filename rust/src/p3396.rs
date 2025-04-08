use std::collections::HashSet;

struct Solution;

impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        let mut operations = 0;
        let mut current_nums = nums;

        while !current_nums.is_empty() {
            let set: HashSet<_> = current_nums.iter().collect();
            if set.len() == current_nums.len() {
                break;
            }
            if current_nums.len() >= 3 {
                current_nums.drain(0..3);
            } else {
                current_nums.clear();
            }
            operations += 1;
        }
        operations
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_minimum_operations() {
        assert_eq!(
            Solution::minimum_operations(vec![1, 2, 3, 4, 2, 3, 3, 5, 7]),
            2
        );
        assert_eq!(Solution::minimum_operations(vec![4, 5, 6, 4, 4]), 2);
        assert_eq!(Solution::minimum_operations(vec![6, 7, 8, 9]), 0);
    }
}
