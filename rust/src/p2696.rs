fn removeabcd(s: &str) -> String {
    s.replace("AB", "").replace("CD", "")
}

impl Solution {
    pub fn min_length(s: String) -> i32 {
        let mut ans = s;
        let mut t = removeabcd(&ans);
        while ans != t {
            ans = t.clone();
            t = removeabcd(&t);
        }
        ans.len() as i32
    }
}
