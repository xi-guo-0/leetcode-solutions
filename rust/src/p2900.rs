use crate::svec;

struct Solution;

impl Solution {
    pub fn get_longest_subsequence(words: Vec<String>, groups: Vec<i32>) -> Vec<String> {
        if words.is_empty() {
            return vec![];
        }
        let mut result = vec![words[0].clone()];
        let mut prev_group = groups[0];
        for i in 1..words.len() {
            if groups[i] != prev_group {
                result.push(words[i].clone());
                prev_group = groups[i];
            }
        }
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_get_longest_subsequence() {
        assert_eq!(
            Solution::get_longest_subsequence(svec!["e", "a", "b"], vec![0, 0, 1]),
            svec!["e", "b"]
        );
        assert_eq!(
            Solution::get_longest_subsequence(svec!["a", "b", "c", "d"], vec![1, 0, 1, 1]),
            svec!["a", "b", "c"]
        );
    }
}
