struct Solution;

impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        fn back_track(s: String, open: i32, close: i32, res: &mut Vec<String>) {
            if open == 0 && close == 0 {
                res.push(s);
                return;
            }
            if open > 0 {
                back_track(s.clone() + "(", open - 1, close + 1, res);
            }
            if close > 0 {
                back_track(s.clone() + ")", open, close - 1, res);
            }
        }
        let mut result = Vec::new();
        back_track("".to_string(), n, 0, &mut result);
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_generate_parenthesis() {
        assert_eq!(
            Solution::generate_parenthesis(3),
            vec!["((()))", "(()())", "(())()", "()(())", "()()()"]
        );
    }
}
