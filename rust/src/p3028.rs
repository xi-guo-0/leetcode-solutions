impl Solution {
    pub fn return_to_boundary_count(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut p = 0;
        for n in nums.iter() {
            p += n;
            if p == 0 {
                ans += 1;
            }
        }
        ans
    }
}
