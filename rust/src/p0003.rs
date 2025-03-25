use std::cmp::max;

struct Solution;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let s = s.chars().collect::<Vec<char>>();
        let mut positions = [-1i32; 256];
        let mut ans = 0i32;
        let mut left = -1i32;
        for i in 0..s.len() {
            left = max(left, positions[s[i] as usize]);
            positions[s[i] as usize] = i as i32;
            ans = max(ans, i as i32 - left);
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_length_of_longest_substring() {
        assert_eq!(
            Solution::length_of_longest_substring(String::from("abcabcbb")),
            3
        );
        assert_eq!(
            Solution::length_of_longest_substring(String::from("bbbbb")),
            1
        );
        assert_eq!(
            Solution::length_of_longest_substring(String::from("pwwkew")),
            3
        );
    }
}
