struct Solution;

impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let words: Vec<&str> = s.trim().split_whitespace().collect();
        words[words.len() - 1].len() as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_length_of_last_word() {
        assert_eq!(
            Solution::length_of_last_word(String::from("Hello World")),
            5
        );
        assert_eq!(
            Solution::length_of_last_word(String::from("   fly me   to   the moon  ")),
            4
        );
        assert_eq!(
            Solution::length_of_last_word(String::from("luffy is still joyboy")),
            6
        );
    }
}
