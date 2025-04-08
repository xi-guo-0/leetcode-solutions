use std::collections::HashMap;

fn sort_string(text: &str) -> String {
    let mut chars: Vec<char> = text.chars().collect();
    chars.sort();
    chars.into_iter().collect()
}

struct Solution;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut map: HashMap<String, usize> = HashMap::new();
        let mut ans: Vec<Vec<String>> = Vec::new();
        for str in strs.into_iter() {
            let s = sort_string(&str);
            if !map.contains_key(&s) {
                let n = map.len();
                map.insert(s.clone(), n);
                ans.push(vec![]);
            }
            ans[*map.get(&s).unwrap()].push(str);
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    fn compare_grouped_anagrams(
        mut actual: Vec<Vec<String>>,
        mut expected: Vec<Vec<String>>,
    ) -> bool {
        for group in actual.iter_mut() {
            group.sort();
        }
        for group in expected.iter_mut() {
            group.sort();
        }
        actual.sort();
        expected.sort();
        actual == expected
    }
    #[test]
    fn test_group_anagrams() {
        let input = vec![
            "eat".to_string(),
            "tea".to_string(),
            "tan".to_string(),
            "ate".to_string(),
            "nat".to_string(),
            "bat".to_string(),
        ];
        let output = Solution::group_anagrams(input);
        let expected = vec![
            vec!["bat".to_string()],
            vec!["nat".to_string(), "tan".to_string()],
            vec!["ate".to_string(), "eat".to_string(), "tea".to_string()],
        ];
        assert!(compare_grouped_anagrams(output, expected));

        let input = vec!["".to_string()];
        let output = Solution::group_anagrams(input);
        let expected = vec![vec!["".to_string()]];
        assert!(compare_grouped_anagrams(output, expected));

        let input = vec!["a".to_string()];
        let output = Solution::group_anagrams(input);
        let expected = vec![vec!["a".to_string()]];
        assert!(compare_grouped_anagrams(output, expected));
    }
}
