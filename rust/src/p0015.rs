struct Solution;

impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut nums = nums;
        let mut ans: Vec<Vec<i32>> = Vec::new();
        let n = nums.len();
        if n < 3 {
            return ans;
        }
        nums.sort();
        for i in 0..n - 2 {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }
            let (mut left, mut right) = (i + 1, n - 1);
            while left < right {
                let sum = nums[i] + nums[left] + nums[right];
                match sum.cmp(&0) {
                    std::cmp::Ordering::Less => {
                        left += 1;

                        while left < right && nums[left] == nums[left - 1] {
                            left += 1;
                        }
                    }
                    std::cmp::Ordering::Greater => {
                        right -= 1;

                        while left < right && nums[right] == nums[right + 1] {
                            right -= 1;
                        }
                    }
                    std::cmp::Ordering::Equal => {
                        ans.push(vec![nums[i], nums[left], nums[right]]);
                        left += 1;
                        right -= 1;

                        while left < right && nums[left] == nums[left - 1] {
                            left += 1;
                        }
                        while left < right && nums[right] == nums[right + 1] {
                            right -= 1;
                        }
                    }
                }
            }
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_three_sum() {
        assert_eq!(
            Solution::three_sum(vec![-1, 0, 1, 2, -1, -4]),
            vec![vec![-1, -1, 2], vec![-1, 0, 1]]
        );
        assert_eq!(Solution::three_sum(vec![0, 1, 1]), Vec::<Vec<i32>>::new());
        assert_eq!(Solution::three_sum(vec![0, 0, 0]), vec![vec![0, 0, 0]]);
    }
}
