struct Solution;

impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        let mut i = m as usize;
        let mut j = n as usize;
        let mut k = (m + n) as usize;
        while 0 < i && 0 < j {
            if nums1[i - 1] <= nums2[j - 1] {
                nums1[k - 1] = nums2[j - 1];
                j -= 1;
            } else {
                nums1[k - 1] = nums1[i - 1];
                i -= 1;
            }
            k -= 1;
        }
        while 0 < i {
            nums1[k - 1] = nums1[i - 1];
            i -= 1;
            k -= 1;
        }
        while 0 < j {
            nums1[k - 1] = nums2[j - 1];
            j -= 1;
            k -= 1;
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_merge() {
        let mut nums1 = vec![1, 2, 3, 0, 0, 0];
        let mut nums2 = vec![2, 5, 6];
        Solution::merge(&mut nums1, 3, &mut nums2, 3);
        assert_eq!(nums1, vec![1, 2, 2, 3, 5, 6]);

        let mut nums1 = vec![1];
        let mut nums2 = vec![];
        Solution::merge(&mut nums1, 1, &mut nums2, 0);
        assert_eq!(nums1, vec![1]);

        let mut nums1 = vec![0];
        let mut nums2 = vec![1];
        Solution::merge(&mut nums1, 0, &mut nums2, 1);
        assert_eq!(nums1, vec![1]);
    }
}
