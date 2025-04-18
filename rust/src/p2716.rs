use std::collections::HashSet;
impl Solution {
    pub fn minimized_string_length(s: String) -> i32 {
        s.chars().collect::<HashSet<char>>().len() as i32
    }
}
