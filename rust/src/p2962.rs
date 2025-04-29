struct Solution;

impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i32) -> i64 {
        let max_ele = nums.iter().max().copied().unwrap_or(0);
        (0..nums.len())
            .scan((0, 0), |(c, l), r| {
                *c += (nums[r] == max_ele) as i32;
                while *c == k {
                    *c -= (nums[*l] == max_ele) as i32;
                    *l += 1;
                }
                Some(*l as i64)
            })
            .sum()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_count_subarrays() {
        assert_eq!(Solution::count_subarrays(vec![1, 3, 2, 3, 3], 2), 6);
        assert_eq!(Solution::count_subarrays(vec![1, 4, 2, 1], 3), 0);
    }
}
