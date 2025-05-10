struct Solution;

impl Solution {
    pub fn min_sum(nums1: Vec<i32>, nums2: Vec<i32>) -> i64 {
        let sum1: i64 = nums1.iter().map(|&x| x as i64).filter(|&x| x != 0).sum();
        let count_zero1 = nums1.iter().filter(|&&x| x == 0).count() as i64;
        let sum2: i64 = nums2.iter().map(|&x| x as i64).filter(|&x| x != 0).sum();
        let count_zero2 = nums2.iter().filter(|&&x| x == 0).count() as i64;
        let min_sum1 = sum1 + count_zero1;
        let min_sum2 = sum2 + count_zero2;
        if min_sum1 > min_sum2 {
            if count_zero2 == 0 {
                return -1;
            }
            min_sum1
        } else if min_sum2 > min_sum1 {
            if count_zero1 == 0 {
                return -1;
            }
            min_sum2
        } else {
            min_sum1
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_min_sum() {
        assert_eq!(Solution::min_sum(vec![3, 2, 0, 1, 0], vec![6, 5, 0]), 12);
        assert_eq!(Solution::min_sum(vec![2, 0, 2, 0], vec![1, 4]), -1);
    }
}
