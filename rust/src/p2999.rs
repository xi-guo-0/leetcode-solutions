use std::cmp::Ordering;

struct Solution;

impl Solution {
    pub fn number_of_powerful_int(start: i64, finish: i64, limit: i32, s: String) -> i64 {
        Self::count_powerful(finish, limit, s.as_str())
            - Self::count_powerful(start - 1, limit, s.as_str())
    }

    fn count_powerful(n: i64, limit: i32, suffix: &str) -> i64 {
        let n_str = n.to_string();
        let total_len = n_str.len();
        let suffix_len = suffix.len();
        if total_len < suffix_len {
            return 0;
        }
        let prefix_len = total_len - suffix_len;
        let suffix_part = &n_str[prefix_len..];
        let suffix_cmp = suffix_part.cmp(suffix);
        let mut dp = vec![vec![0; 2]; prefix_len + 1];
        dp[prefix_len][0] = 1;
        dp[prefix_len][1] = if suffix_cmp != Ordering::Less { 1 } else { 0 };
        for i in (0..prefix_len).rev() {
            let current_digit = n_str.chars().nth(i).unwrap().to_digit(10).unwrap() as i32;
            let max_digit = if current_digit <= limit {
                current_digit
            } else {
                limit
            };
            dp[i][0] = (limit + 1) as i64 * dp[i + 1][0];
            if current_digit <= limit {
                dp[i][1] = current_digit as i64 * dp[i + 1][0] + dp[i + 1][1];
            } else {
                dp[i][1] = (limit + 1) as i64 * dp[i + 1][0];
            }
        }
        dp[0][1]
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_number_of_powerful_int() {
        assert_eq!(
            Solution::number_of_powerful_int(1, 6000, 4, "124".to_string()),
            5
        );
        assert_eq!(
            Solution::number_of_powerful_int(15, 215, 6, "10".to_string()),
            2
        );
        assert_eq!(
            Solution::number_of_powerful_int(1000, 2000, 4, "3000".to_string()),
            0
        );
    }
}
