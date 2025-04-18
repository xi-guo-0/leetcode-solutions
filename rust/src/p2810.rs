impl Solution {
    pub fn final_string(s: String) -> String {
        let mut ans = String::new();
        for c in s.chars() {
            if (c == 'i') {
                ans = ans.chars().rev().collect();
            } else {
                ans.push(c);
            }
        }
        ans
    }
}
