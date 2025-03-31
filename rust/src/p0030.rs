use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        let mut substrings_starts = Vec::new();
        let mut words_dict: HashMap<&str, i32> = HashMap::new();
        let step = words[0].len();
        for word in words.iter() {
            *words_dict.entry(word).or_insert(0) += 1;
        }
        for i in 0..step {
            let mut start = i;
            let mut current_words = HashMap::new();
            for j in (i..(s.len() + 1)).step_by(step).skip(1) {
                let word = &s[(j - step)..j];
                if let Some(&required_count) = words_dict.get(word) {
                    *current_words.entry(word).or_insert(0) += 1;
                    while current_words[word] > required_count {
                        let word_to_drop = &s[start..(start + step)];
                        *current_words.get_mut(word_to_drop).unwrap() -= 1;
                        start += step
                    }
                    if j - start == words.len() * step {
                        substrings_starts.push(start as i32);
                    }
                } else {
                    start = j;
                    current_words = HashMap::new();
                }
            }
        }
        substrings_starts
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_find_substring() {
        assert_eq!(
            Solution::find_substring(
                String::from("barfoothefoobarman"),
                vec!["foo", "bar"].into_iter().map(String::from).collect()
            ),
            vec![0, 9]
        );
        assert_eq!(
            Solution::find_substring(
                String::from("wordgoodgoodgoodbestword"),
                vec!["word", "good", "best", "word"]
                    .into_iter()
                    .map(String::from)
                    .collect()
            ),
            Vec::<i32>::new()
        );
        assert_eq!(
            Solution::find_substring(
                String::from("barfoofoobarthefoobarman"),
                vec!["bar", "foo", "the"]
                    .into_iter()
                    .map(String::from)
                    .collect()
            ),
            vec![6, 9, 12]
        );
    }
}
