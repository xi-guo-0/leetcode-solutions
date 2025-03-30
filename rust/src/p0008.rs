struct Solution;

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let s = s.trim_start();
        let (s, sign) = if s.starts_with('-') {
            (&s[1..], -1)
        } else if s.starts_with('+') {
            (&s[1..], 1)
        } else {
            (s, 1)
        };
        let mut result: i32 = 0;
        for c in s.chars() {
            if let Some(digit) = c.to_digit(10) {
                if result > i32::MAX / 10
                    || (result == i32::MAX / 10 && digit as i32 > i32::MAX % 10)
                {
                    return if sign == 1 { i32::MAX } else { i32::MIN };
                }
                result = result * 10 + digit as i32;
            } else {
                break;
            }
        }
        result * sign
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_my_atoi() {
        assert_eq!(Solution::my_atoi(String::from("42")), 42);
        assert_eq!(Solution::my_atoi(String::from("-042")), -42);
        assert_eq!(Solution::my_atoi(String::from("1337c0d3")), 1337);
        assert_eq!(Solution::my_atoi(String::from("0-1")), 0);
        assert_eq!(Solution::my_atoi(String::from("words and 987")), 0);
        assert_eq!(Solution::my_atoi(String::from("-91283472332")), -2147483648);
    }
}
