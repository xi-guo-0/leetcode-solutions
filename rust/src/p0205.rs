use std::collections::HashMap;

fn convert(s: &String) -> String {
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

impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        convert(&s) == convert(&t)
    }
}
