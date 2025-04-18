use std::collections::HashMap;

fn smaller_string(s: String) -> String {
    let r = s.chars().rev().collect();
    std::cmp::min(s.to_string(), r)
}

fn count_occurrences(vs: Vec<String>) -> HashMap<String, i32> {
    let mut map: HashMap<String, i32> = HashMap::new();
    for word in vs.iter() {
        *map.entry(word.clone()).or_default() += 1;
    }
    map
}

impl Solution {
    pub fn maximum_number_of_string_pairs(words: Vec<String>) -> i32 {
        count_occurrences(words.into_iter().map(smaller_string).collect())
            .values()
            .map(|x| x / 2)
            .sum()
    }
}
