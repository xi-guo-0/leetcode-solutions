impl Solution {
    pub fn longest_ideal_string(s: String, k: i32) -> i32 {
        let mut dp = vec![0i32; 128];
        let s = s.into_bytes();
        for c in s.into_iter() {
            let l = c as usize - k as usize;
            let r = std::cmp::min(c as usize + k as usize, 127);
            dp[c as usize] = dp[l..=r].iter().max().unwrap() + 1;
        }
        dp.into_iter().max().unwrap()
    }
}
