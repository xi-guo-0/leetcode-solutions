use std::collections::HashSet;

fn count_common(nums1: &Vec<i32>, nums2: &Vec<i32>) -> i32 {
    let s: HashSet<_> = nums2.iter().cloned().collect();
    nums1.iter().filter(|x| s.contains(x)).count() as i32
}

impl Solution {
    pub fn find_intersection_values(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        vec![count_common(&nums1, &nums2), count_common(&nums2, &nums1)]
    }
}
