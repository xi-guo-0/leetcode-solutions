use std::collections::{HashMap, HashSet};

struct Solution;

impl Solution {
    pub fn count_complete_subarrays(nums: Vec<i32>) -> i32 {
        let k = {
            let mut set = HashSet::new();
            for &num in &nums {
                set.insert(num);
            }
            set.len() as i32
        };
        if k == 0 {
            return 0;
        }
        let count_k = Self::count_at_most(&nums, k);
        let count_km1 = Self::count_at_most(&nums, k - 1);
        count_k - count_km1
    }

    fn count_at_most(nums: &Vec<i32>, m: i32) -> i32 {
        let mut left = 0;
        let mut freq = HashMap::new();
        let mut res = 0;
        for right in 0..nums.len() {
            *freq.entry(nums[right]).or_insert(0) += 1;
            while freq.len() > m as usize {
                let left_val = nums[left];
                *freq.get_mut(&left_val).unwrap() -= 1;
                if freq[&left_val] == 0 {
                    freq.remove(&left_val);
                }
                left += 1;
            }
            res += right as i32 - left as i32 + 1;
        }
        res
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_count_complete_subarrays() {
        assert_eq!(Solution::count_complete_subarrays(vec![1, 3, 1, 2, 2]), 4);
        assert_eq!(Solution::count_complete_subarrays(vec![5, 5, 5, 5]), 10);
    }
}
