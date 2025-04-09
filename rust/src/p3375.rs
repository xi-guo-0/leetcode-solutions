struct Solution;

impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        let mut unique_sorted_numbers = nums;
        unique_sorted_numbers.sort();
        unique_sorted_numbers.dedup();

        let smallest_number = unique_sorted_numbers[0];
        let unique_count = unique_sorted_numbers.len() as i32;

        if smallest_number < k {
            -1
        } else if smallest_number == k {
            unique_count - 1
        } else {
            unique_count
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_min_operations() {
        assert_eq!(Solution::min_operations(vec![5, 2, 5, 4, 5], 2), 2);
        assert_eq!(Solution::min_operations(vec![2, 1, 2], 2), -1);
        assert_eq!(Solution::min_operations(vec![9, 7, 5, 3], 1), 4);
    }
}
