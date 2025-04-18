impl Solution {
    pub fn count_key_changes(s: String) -> i32 {
        let s: Vec<char> = s.to_lowercase().chars().collect();
        let mut ans = 0;
        for i in 1..s.len() {
            if s[i - 1] != s[i] {
                ans += 1;
            }
        }
        ans
    }
}
