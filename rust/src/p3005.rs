use std::collections::HashMap;

fn count_occurrences<T: Clone + Eq + std::hash::Hash>(xs: Vec<T>) -> HashMap<T, i32> {
    let mut map: HashMap<T, i32> = HashMap::new();
    for x in xs.iter() {
        *map.entry(x.clone()).or_default() += 1;
    }
    map
}

impl Solution {
    pub fn max_frequency_elements(nums: Vec<i32>) -> i32 {
        let oc = count_occurrences(nums);
        let mf = *oc.values().max().unwrap();
        oc.values().map(|x| if *x == mf { mf } else { 0 }).sum()
    }
}
