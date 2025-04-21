struct Solution;

impl Solution {
    pub fn number_of_arrays(differences: Vec<i32>, lower: i32, upper: i32) -> i32 {
        let mut current_sum = 0i64;
        let mut min_sum = 0i64;
        let mut max_sum = 0i64;
        for &diff in &differences {
            current_sum += diff as i64;
            min_sum = min_sum.min(current_sum);
            max_sum = max_sum.max(current_sum);
        }
        let required_width = max_sum - min_sum;
        let available_width = upper as i64 - lower as i64;
        let possible_count = available_width - required_width + 1;
        if possible_count > 0 {
            possible_count as i32
        } else {
            0
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_number_of_arrays() {
        assert_eq!(Solution::number_of_arrays(vec![1, -3, 4], 1, 6), 2);
        assert_eq!(Solution::number_of_arrays(vec![3, -4, 5, 1, -2], -4, 5), 4);
        assert_eq!(Solution::number_of_arrays(vec![4, -7, 2], 3, 6), 0);
    }
}
