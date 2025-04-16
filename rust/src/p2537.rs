use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn count_good(nums: Vec<i32>, k: i32) -> i64 {
        let n = nums.len();
        let mut good_pairs = 0;
        let mut right = 0;
        let mut counts = HashMap::new();
        let mut ans = 0i64;
        for left in 0..n {
            while good_pairs < k && right < n {
                let num = nums[right];
                let count = counts.get(&num).copied().unwrap_or(0);
                good_pairs += count;
                *counts.entry(num).or_insert(0) += 1;
                right += 1;
            }
            if good_pairs >= k {
                ans += (n - right + 1) as i64;
            }
            let num = nums[left];
            if let Some(count) = counts.get_mut(&num) {
                *count -= 1;
                good_pairs -= *count;
            }
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_count_good() {
        assert_eq!(Solution::count_good(vec![1, 1, 1, 1, 1], 10), 1);
        assert_eq!(Solution::count_good(vec![3, 1, 4, 3, 2, 2, 4], 2), 4);
    }
}
