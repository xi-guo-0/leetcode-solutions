impl Solution {
    pub fn compare_version(version1: String, version2: String) -> i32 {
        let mut nums0 = version1.split('.').map(|s| s.parse().unwrap());
        let mut nums1 = version2.split('.').map(|s| s.parse().unwrap());
        loop {
            match (nums0.next(), nums1.next()) {
                (Some(nums0), nums1) if nums0 > nums1.unwrap_or(0) => return 1,
                (nums0, Some(nums1)) if nums1 > nums0.unwrap_or(0) => return -1,
                (None, None) => return 0,
                _ => continue,
            }
        }
    }
}
