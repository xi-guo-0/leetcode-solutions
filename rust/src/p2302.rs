struct Solution;

impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i64) -> i64 {
        let mut sum = 0;
        let mut count = 0;
        let mut left = 0;
        for (right, &num) in nums.iter().enumerate() {
            sum += num as i64;
            while sum * (right - left + 1) as i64 >= k {
                sum -= nums[left] as i64;
                left += 1;
            }
            count += right - left + 1;
        }
        count as i64
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_count_subarrays() {
        assert_eq!(Solution::count_subarrays(vec![2, 1, 4, 3, 5], 10), 6);
        assert_eq!(Solution::count_subarrays(vec![1, 1, 1], 5), 5);
    }
}
