struct Solution;

impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        match haystack.find(&needle) {
            Some(i) => i as i32,
            None => -1,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_str_str() {
        assert_eq!(
            Solution::str_str(String::from("sadbutsad"), String::from("sad")),
            0
        );
        assert_eq!(
            Solution::str_str(String::from("leetcode"), String::from("leeto")),
            -1
        );
    }
}
