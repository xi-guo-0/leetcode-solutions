impl Solution {
    pub fn maximum_strong_pair_xor(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        for x in nums.iter() {
            for y in nums.iter() {
                if (x - y).abs() <= std::cmp::min(*x, *y) {
                    ans = std::cmp::max(ans, (*x) ^ (*y));
                }
            }
        }
        ans
    }
}
