use std::collections::VecDeque;

struct Solution;

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack = VecDeque::<usize>::new();
        for ch in s.chars() {
            let idx = Self::to_index(ch);
            if idx % 2 == 0 {
                stack.push_back(idx);
            } else if !stack.is_empty() && stack.back().unwrap() + 1 == idx {
                stack.pop_back();
            } else {
                return false;
            }
        }
        stack.is_empty()
    }

    fn to_index(ch: char) -> usize {
        match ch {
            '(' => 0,
            ')' => 1,
            '{' => 2,
            '}' => 3,
            '[' => 4,
            _ => 5,
        }
    }
}

#[cfg(test)]
mod tests {
    use std::str::FromStr;

    use super::*;

    #[test]
    fn test_is_valid() {
        assert_eq!(Solution::is_valid(String::from("()")), true);
        assert_eq!(Solution::is_valid(String::from("()[]{}")), true);
        assert_eq!(Solution::is_valid(String::from("(]")), false);
        assert_eq!(Solution::is_valid(String::from("([])")), true);
    }
}
