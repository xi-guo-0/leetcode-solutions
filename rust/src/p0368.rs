struct Solution;

impl Solution {
    pub fn largest_divisible_subset(nums: Vec<i32>) -> Vec<i32> {
        if nums.is_empty() {
            return vec![];
        }
        let mut nums = nums;
        nums.sort();
        let n = nums.len();
        let mut dp = vec![1; n];
        let mut prev = vec![-1; n];
        let mut max_index = 0;
        for i in 1..n {
            for j in 0..i {
                if nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1 {
                    dp[i] = dp[j] + 1;
                    prev[i] = j as i32;
                }
            }
            if dp[i] > dp[max_index] {
                max_index = i;
            }
        }
        let mut result = Vec::new();
        let mut current = max_index as i32;
        while current != -1 {
            result.push(nums[current as usize]);
            current = prev[current as usize];
        }
        result.reverse();
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_largest_divisible_subset() {
        assert_eq!(
            Solution::largest_divisible_subset(vec![1, 2, 3]),
            vec![1, 2]
        );
        assert_eq!(
            Solution::largest_divisible_subset(vec![1, 2, 4, 8]),
            vec![1, 2, 4, 8]
        );
    }
}
