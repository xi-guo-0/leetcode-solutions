struct Solution;

impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut steps = vec![i32::MAX; n];
        steps[0] = 0;
        for (i, c) in nums.into_iter().enumerate() {
            if steps[i] < i32::MAX {
                for j in i + 1..=std::cmp::min(n - 1, i + c as usize) {
                    steps[j] = std::cmp::min(steps[j], steps[i] + 1);
                }
            }
        }
        steps[n - 1]
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_jump() {
        assert_eq!(Solution::jump(vec![2, 3, 1, 1, 4]), 2);
        assert_eq!(Solution::jump(vec![2, 3, 0, 1, 4]), 2);
    }
}
