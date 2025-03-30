struct Solution;

impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let s = s.as_bytes();
        let p = p.as_bytes();
        let m = s.len();
        let n = p.len();
        let mut dp = vec![vec![false; n + 1]; m + 1];
        dp[0][0] = true;
        for j in 1..=n {
            if p[j - 1] == b'*' {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for i in 1..=m {
            for j in 1..=n {
                match p[j - 1] {
                    b'.' => dp[i][j] = dp[i - 1][j - 1],
                    c if c == s[i - 1] => dp[i][j] = dp[i - 1][j - 1],
                    b'*' => {
                        dp[i][j] = dp[i][j - 2]
                            || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == b'.'));
                    }
                    _ => {}
                }
            }
        }
        dp[m][n]
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_is_match() {
        assert_eq!(
            Solution::is_match(String::from("aa"), String::from("a")),
            false
        );
        assert_eq!(
            Solution::is_match(String::from("aa"), String::from("a*")),
            true
        );
        assert_eq!(
            Solution::is_match(String::from("ab"), String::from(".*")),
            true
        );
    }
}
