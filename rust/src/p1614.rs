impl Solution {
    pub fn max_depth(s: String) -> i32 {
        let mut ans = 0;
        let mut depth = 0;
        for c in s.chars() {
            if c == '(' {
                depth += 1;
                ans = std::cmp::max(ans, depth);
            } else if c == ')' {
                depth -= 1;
            }
        }
        ans
    }
}
