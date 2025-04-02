struct Solution;

impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let mut stack = vec![-1];
        let mut max_len = 0;
        for (i, c) in s.chars().enumerate() {
            let i = i as i32;
            if c == '(' {
                stack.push(i);
            } else {
                stack.pop();
                if stack.is_empty() {
                    stack.push(i);
                } else {
                    max_len = max_len.max(i - stack.last().unwrap());
                }
            }
        }
        max_len
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_longest_valid_parentheses() {
        assert_eq!(Solution::longest_valid_parentheses("(()".to_string()), 2);
        assert_eq!(Solution::longest_valid_parentheses(")()())".to_string()), 4);
        assert_eq!(Solution::longest_valid_parentheses("".to_string()), 0);
        assert_eq!(Solution::longest_valid_parentheses("()(()".to_string()), 2);
        assert_eq!(Solution::longest_valid_parentheses("()(())".to_string()), 6);
        assert_eq!(
            Solution::longest_valid_parentheses(")()())()()(".to_string()),
            4
        );
    }
}
