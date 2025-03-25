struct Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let n = s.len();
        if n <= 1 {
            return s;
        }

        let chars: Vec<char> = s.chars().collect();
        let mut dp = vec![vec![false; n]; n];
        let mut start = 0;
        let mut max_len = 1;

        for i in 0..n {
            dp[i][i] = true;
        }

        for i in 0..n - 1 {
            if chars[i] == chars[i + 1] {
                dp[i][i + 1] = true;
                start = i;
                max_len = 2;
            }
        }

        for len in 3..=n {
            for i in 0..=n - len {
                let j = i + len - 1;
                if chars[i] == chars[j] && dp[i + 1][j - 1] {
                    dp[i][j] = true;
                    if len > max_len {
                        start = i;
                        max_len = len;
                    }
                }
            }
        }

        chars[start..start + max_len].iter().collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_longest_palindrome() {
        assert_eq!(
            Solution::longest_palindrome(String::from("babad")),
            String::from("bab")
        );
        assert_eq!(
            Solution::longest_palindrome(String::from("cbbd")),
            String::from("bb")
        );
    }
}
