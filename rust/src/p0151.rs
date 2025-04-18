impl Solution {
    pub fn reverse_words(s: String) -> String {
        s.split(' ')
            .filter(|s| !s.is_empty())
            .rev()
            .collect::<Vec<_>>()
            .join(" ")
    }
}
