struct Solution;

impl Solution {
    pub fn check_valid_string(s: String) -> bool {
        let mut l = 0;
        let mut r = 0;
        let s: Vec<char> = s.chars().collect();
        for i in 0..s.len() {
            match s[i] {
                ')' => l -= 1,
                _ => l += 1,
            }
            match s[s.len() - 1 - i] {
                '(' => r -= 1,
                _ => r += 1,
            }
            if l < 0 || r < 0 {
                return false;
            }
        }
        true
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_check_valid_string() {
        assert_eq!(Solution::check_valid_string(String::from("()")), true);
        assert_eq!(Solution::check_valid_string(String::from("(*)")), true);
        assert_eq!(Solution::check_valid_string(String::from("(*))")), true);
    }
}
