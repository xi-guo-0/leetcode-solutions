fn is_numeric_str(s: &str) -> bool {
    s.chars().all(|c| '0' <= c && c <= '9')
}

fn get_value(s: &str) -> i32 {
    if is_numeric_str(s) {
        s.parse::<i32>().unwrap()
    } else {
        s.len() as i32
    }
}

impl Solution {
    pub fn maximum_value(strs: Vec<String>) -> i32 {
        strs.iter().map(|s| get_value(s)).max().unwrap()
    }
}
