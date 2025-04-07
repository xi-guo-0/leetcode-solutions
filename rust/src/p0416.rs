struct Solution;

impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let sum: i32 = nums.iter().sum();
        if sum % 2 != 0 {
            return false;
        }
        let target = sum / 2;
        let mut dp = vec![false; (target + 1) as usize];
        dp[0] = true;

        for num in nums {
            for i in (num..=target).rev() {
                let i = i as usize;
                let prev = (i as i32 - num) as usize;
                dp[i] = dp[i] || dp[prev];
            }
        }

        dp[target as usize]
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_can_partition() {
        assert_eq!(Solution::can_partition(vec![1, 5, 11, 5]), true);
        assert_eq!(Solution::can_partition(vec![1, 2, 3, 5]), false);
    }
}
