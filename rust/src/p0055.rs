use std::cmp;

struct Solution;

impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let mut max_val: i32 = 0;
        for (idx, val) in nums.iter().enumerate() {
            if idx as i32 > max_val {
                return false;
            }
            max_val = cmp::max(max_val, (idx as i32 + *val as i32) as i32);
        }
        return true;
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_can_jump() {
        assert_eq!(Solution::can_jump(vec![2, 3, 1, 1, 4]), true);
        assert_eq!(Solution::can_jump(vec![3, 2, 1, 0, 4]), false);
    }
}
