struct Solution;

impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        if n < 3 {
            return 0;
        }
        let mut max_left = vec![0; n];
        max_left[0] = nums[0];
        for j in 1..n {
            max_left[j] = max_left[j - 1].max(nums[j]);
        }
        let mut max_right = vec![0; n];
        max_right[n - 1] = nums[n - 1];
        for j in (0..n - 1).rev() {
            max_right[j] = max_right[j + 1].max(nums[j]);
        }
        let mut max_value: i64 = 0;
        for j in 1..n - 1 {
            let current_value = (max_left[j - 1] - nums[j]) as i64 * max_right[j + 1] as i64;
            max_value = max_value.max(current_value);
        }
        max_value
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_maximum_triplet_value() {
        assert_eq!(Solution::maximum_triplet_value(vec![12, 6, 1, 2, 7]), 77);
        assert_eq!(Solution::maximum_triplet_value(vec![1, 10, 3, 4, 19]), 133);
        assert_eq!(Solution::maximum_triplet_value(vec![1, 2, 3]), 0);
        assert_eq!(
            Solution::maximum_triplet_value(vec![1000000, 1, 1000000]),
            999999000000
        );
    }
}
