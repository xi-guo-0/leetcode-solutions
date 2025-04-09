struct Solution;

impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let s = s.as_bytes();
        let n = s.len();
        let mut i = 0;
        for c in t.chars() {
            if i == n {
                break;
            } else if s[i] == c as u8 {
                i += 1;
            }
        }
        i == n
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_is_subsequence() {
        assert!(Solution::is_subsequence(
            "abc".to_string(),
            "ahbgdc".to_string(),
        ));
        assert!(!Solution::is_subsequence(
            "axc".to_string(),
            "ahbgdc".to_string(),
        ));
    }
}
