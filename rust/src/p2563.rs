struct Solution;

impl Solution {
    pub fn count_fair_pairs(nums: Vec<i32>, lower: i32, upper: i32) -> i64 {
        let mut nums = nums;
        nums.sort();
        let mut count = 0i64;
        let n = nums.len();
        for i in 0..n {
            let mut left = i + 1;
            let mut right = n - 1;
            let mut lower_bound = lower - nums[i];
            let mut upper_bound = upper - nums[i];
            let mut low = left;
            let mut high = right;
            let mut start = n;
            while low <= high {
                let mid = low + (high - low) / 2;
                if nums[mid] >= lower_bound {
                    start = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            low = left;
            high = right;
            let mut end = left - 1;
            while low <= high {
                let mid = low + (high - low) / 2;
                if nums[mid] <= upper_bound {
                    end = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if start <= end {
                count += (end - start + 1) as i64;
            }
        }
        count
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_count_fair_pairs() {
        assert_eq!(Solution::count_fair_pairs(vec![0, 1, 7, 4, 4, 5], 3, 6), 6);
        assert_eq!(Solution::count_fair_pairs(vec![1, 7, 9, 2, 5], 11, 11), 1);
    }
}
