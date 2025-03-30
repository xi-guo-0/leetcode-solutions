struct Solution;

impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut n = 0usize;
        let mut cont = true;
        for i in 0..strs[0].len() {
            let t = n + 1;
            for j in 0..strs.len() {
                if strs[j].len() < t
                    || strs[j].chars().nth(i).unwrap() != strs[0].chars().nth(i).unwrap()
                {
                    cont = false;
                    break;
                }
            }
            if !cont {
                break;
            }
            n += 1;
        }
        strs[0][0..n].to_string()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_longest_common_prefix() {
        assert_eq!(
            Solution::longest_common_prefix(
                vec!["flower", "flow", "flight"]
                    .into_iter()
                    .map(String::from)
                    .collect()
            ),
            "fl"
        );
        assert_eq!(
            Solution::longest_common_prefix(
                vec!["dog", "racecar", "car"]
                    .into_iter()
                    .map(String::from)
                    .collect()
            ),
            ""
        );
    }
}
