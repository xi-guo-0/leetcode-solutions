struct Solution;

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let (nums1, nums2) = if nums1.len() > nums2.len() {
            (nums2, nums1)
        } else {
            (nums1, nums2)
        };

        let m = nums1.len();
        let n = nums2.len();
        let mut left = 0;
        let mut right = m;

        while left <= right {
            let partition1 = (left + right) / 2;
            let partition2 = (m + n + 1) / 2 - partition1;
            let max_left1 = if partition1 == 0 {
                i32::MIN
            } else {
                nums1[partition1 - 1]
            };
            let min_right1 = if partition1 == m {
                i32::MAX
            } else {
                nums1[partition1]
            };
            let max_left2 = if partition2 == 0 {
                i32::MIN
            } else {
                nums2[partition2 - 1]
            };
            let min_right2 = if partition2 == n {
                i32::MAX
            } else {
                nums2[partition2]
            };
            if max_left1 <= min_right2 && max_left2 <= min_right1 {
                if (m + n) % 2 == 0 {
                    let left_max = max_left1.max(max_left2);
                    let right_min = min_right1.min(min_right2);
                    return (left_max + right_min) as f64 / 2.0;
                } else {
                    return max_left1.max(max_left2) as f64;
                }
            } else if max_left1 > min_right2 {
                right = partition1 - 1;
            } else {
                left = partition1 + 1;
            }
        }
        0.0
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_find_median_sorted_arrays() {
        assert_eq!(
            Solution::find_median_sorted_arrays(vec![1, 3], vec![2]),
            2.0
        );
        assert_eq!(
            Solution::find_median_sorted_arrays(vec![1, 2], vec![3, 4]),
            2.5
        );
    }
}
