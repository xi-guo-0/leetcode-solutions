use std::str::FromStr;

impl Solution {
    pub fn are_numbers_ascending(s: String) -> bool {
        let numbers: Vec<_> = s
            .split(' ')
            .map(|w| i32::from_str(w))
            .filter(|r| r.is_ok())
            .map(|n| n.unwrap())
            .collect();
        for i in 1..numbers.len() {
            if numbers[i] <= numbers[i - 1] {
                return false;
            }
        }
        true
    }
}
