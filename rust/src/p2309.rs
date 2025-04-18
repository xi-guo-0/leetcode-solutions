impl Solution {
    pub fn greatest_letter(s: String) -> String {
        let mut oc = [false; 128];
        for c in s.chars() {
            oc[c as usize] = true;
        }
        for c in ('A'..='Z').rev() {
            if oc[c as usize] && oc[c.to_ascii_lowercase() as usize] {
                return c.to_string();
            }
        }
        "".to_string()
    }
}
