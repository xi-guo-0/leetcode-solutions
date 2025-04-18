use std::collections::HashMap;

fn convert_s(s: String) -> String {
    let mut ch: u8 = 0;
    let mut ans = String::new();
    let mut map: HashMap<char, char> = HashMap::new();
    for c in s.chars() {
        if !map.contains_key(&c) {
            map.insert(c, ch as char);
            ch += 1;
        }
        ans.push(*map.get(&c).unwrap());
    }
    ans
}

fn convert_vs(vs: Vec<String>) -> String {
    let mut ch: u8 = 0;
    let mut ans = String::new();
    let mut map: HashMap<String, char> = HashMap::new();
    for c in vs.iter() {
        if !map.contains_key(&c.clone()) {
            map.insert(c.clone(), ch as char);
            ch += 1;
        }
        ans.push(*map.get(&c.clone()).unwrap());
    }
    ans
}

impl Solution {
    pub fn word_pattern(pattern: String, s: String) -> bool {
        convert_s(pattern) == convert_vs(s.split(" ").map(String::from).collect())
    }
}
