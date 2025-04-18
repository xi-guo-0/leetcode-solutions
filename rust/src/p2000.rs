impl Solution {
    pub fn reverse_prefix(word: String, ch: char) -> String {
        if let Some(idx) = word.find(ch) {
            return word[0..=idx].chars().rev().collect::<String>() + &word[(idx + 1)..word.len()];
        }
        word
    }
}
