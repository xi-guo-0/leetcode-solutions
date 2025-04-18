impl Solution {
    pub fn find_middle_index(nums: Vec<i32>) -> i32 {
        let s = nums.iter().sum::<i32>();
        let mut t = 0;
        for (i, n) in nums.into_iter().enumerate() {
            if t + t + n == s {
                return i as i32;
            }
            t += n;
        }
        -1
    }
}
