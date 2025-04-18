use std::collections::BTreeSet;
use std::collections::HashMap;

fn standard_form(s: &str) -> String {
    s.chars().collect::<BTreeSet<char>>().into_iter().collect()
}

fn count_occurrences(xs: Vec<String>) -> HashMap<String, usize> {
    let mut map: HashMap<String, usize> = HashMap::new();
    for x in xs.into_iter() {
        *map.entry(standard_form(&x)).or_default() += 1;
    }
    map
}

impl Solution {
    pub fn similar_pairs(words: Vec<String>) -> i32 {
        count_occurrences(words)
            .values()
            .map(|x| x * (x - 1) / 2)
            .sum::<usize>() as i32
    }
}
