struct Solution;

impl Solution {
    pub fn score_of_string(s: String) -> i32 {
        let s: Vec<i32> = s.chars().map(|c| c as i32).collect();
        let mut ans = 0;
        for i in 1..s.len() {
            ans += (s[i] - s[i - 1]).abs()
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_score_of_string() {
        assert_eq!(Solution::score_of_string("hello".to_string()), 13);
        assert_eq!(Solution::score_of_string("zaz".to_string()), 50);
    }
}
