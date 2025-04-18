impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        Self::is_palindrome_vec(&Self::convert(&s))
    }

    fn is_palindrome_vec(s: &Vec<char>) -> bool {
        let n = s.len();
        for i in 0..(n + 1) / 2 {
            if s[i] != s[n - i - 1] {
                return false;
            }
        }
        true
    }

    fn convert(s: &str) -> Vec<char> {
        s.chars()
            .filter(|c| c.is_ascii_alphanumeric())
            .map(|c| c.to_ascii_lowercase())
            .collect()
    }
}
