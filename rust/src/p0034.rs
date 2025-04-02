struct Solution;

impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let first_pos = Self::find_first(&nums, target);
        let last_pos = Self::find_last(&nums, target);

        if first_pos != -1 && last_pos != -1 {
            vec![first_pos, last_pos]
        } else {
            vec![-1, -1]
        }
    }

    fn find_first(nums: &[i32], target: i32) -> i32 {
        if let Ok(pos) = nums.binary_search(&target) {
            let mut left = pos;
            while left > 0 && nums[left - 1] == target {
                left -= 1;
            }
            return left as i32;
        }
        -1
    }

    fn find_last(nums: &[i32], target: i32) -> i32 {
        if let Ok(pos) = nums.binary_search(&target) {
            let mut right = pos;
            while right < nums.len() - 1 && nums[right + 1] == target {
                right += 1;
            }
            return right as i32;
        }
        -1
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_search_range() {
        assert_eq!(
            Solution::search_range(vec![5, 7, 7, 8, 8, 10], 8),
            vec![3, 4]
        );
        assert_eq!(
            Solution::search_range(vec![5, 7, 7, 8, 8, 10], 6),
            vec![-1, -1]
        );
        assert_eq!(Solution::search_range(vec![], 0), vec![-1, -1]);
    }
}
