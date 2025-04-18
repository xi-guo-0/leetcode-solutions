impl Solution {
    pub fn is_acronym(words: Vec<String>, s: String) -> bool {
        words
            .iter()
            .map(|word| word.chars().nth(0).unwrap())
            .collect::<String>()
            == s
    }
}
