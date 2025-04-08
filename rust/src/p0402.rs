struct Solution;

impl Solution {
    pub fn remove_kdigits(num: String, k: i32) -> String {
        let mut stack = Vec::new();
        let mut remaining = k as usize;
        for c in num.chars() {
            while remaining > 0 && !stack.is_empty() && stack.last().unwrap() > &c {
                stack.pop();
                remaining -= 1;
            }
            stack.push(c);
        }
        stack.truncate(stack.len() - remaining);
        let result: String = stack.into_iter().collect();
        let result = result.trim_start_matches('0').to_string();
        if result.is_empty() {
            "0".to_string()
        } else {
            result
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_remove_kdigits() {
        assert_eq!(Solution::remove_kdigits(String::from("1432219"), 3), "1219");
        assert_eq!(Solution::remove_kdigits(String::from("10200"), 1), "200");
        assert_eq!(Solution::remove_kdigits(String::from("10"), 2), "0");
    }
}
