struct Solution;

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut res = -1;
        let mut first = 0;
        let mut last = nums.len();
        while first != last {
            let mid = first + (last - first) / 2;
            if nums[mid] == target {
                res = mid as i32;
                break;
            } else if nums[first] <= nums[mid] {
                if nums[first] <= target && target < nums[mid] {
                    last = mid;
                } else {
                    first = mid + 1;
                }
            } else {
                if nums[mid] < target && target <= nums[last - 1] {
                    first = mid + 1;
                } else {
                    last = mid;
                }
            }
        }
        res
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_search() {
        assert_eq!(Solution::search(vec![4, 5, 6, 7, 0, 1, 2], 0), 4);
        assert_eq!(Solution::search(vec![4, 5, 6, 7, 0, 1, 2], 3), -1);
        assert_eq!(Solution::search(vec![1], 0), -1);
    }
}
