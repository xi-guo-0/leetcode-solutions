impl Solution {
    pub fn make_good(s: String) -> String {
        let mut ans = String::new();
        for c in s.chars() {
            if let Some(last) = ans.pop() {
                if !(last.eq_ignore_ascii_case(&c) && last != c) {
                    ans.push(last);
                    ans.push(c);
                }
            } else {
                ans.push(c);
            }
        }
        ans
    }
}

