impl Solution {
    pub fn count_seniors(details: Vec<String>) -> i32 {
        details
            .into_iter()
            .filter(|s| 60 < s[11..13].parse::<i32>().unwrap())
            .count() as i32
    }
}
