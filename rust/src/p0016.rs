struct Solution;

impl Solution {
    pub fn three_sum_closest(nums: Vec<i32>, target: i32) -> i32 {
        let mut nums = nums;
        nums.sort();
        let mut closest_sum = i32::MAX;
        for i in 0..nums.len() - 2 {
            let (mut left, mut right) = (i + 1, nums.len() - 1);
            while left < right {
                let current_sum = nums[i] + nums[left] + nums[right];
                if current_sum == target {
                    return target;
                }
                if (current_sum - target).abs() < (closest_sum - target).abs() {
                    closest_sum = current_sum;
                }
                if current_sum < target {
                    left += 1;
                } else {
                    right -= 1;
                }
            }
        }
        closest_sum
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_three_sum_closest() {
        assert_eq!(Solution::three_sum_closest(vec![-1, 2, 1, -4], 1), 2);
        assert_eq!(Solution::three_sum_closest(vec![0, 0, 0], 1), 0);
    }
}
