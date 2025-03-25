struct Solution;

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows < 2 {
            return s;
        }
        let mut ans = String::new();
        let base = ((num_rows - 1) * 2) as usize;
        for diff in 0..(num_rows as usize) {
            for i in (0..s.len()).step_by(base) {
                if i + diff < s.len() {
                    ans.push(s.chars().nth(i + diff).unwrap());
                }
                if diff != 0 && diff + 1 != num_rows as usize && i + base - diff < s.len() {
                    ans.push(s.chars().nth(i + base - diff).unwrap());
                }
            }
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_convert() {
        assert_eq!(
            Solution::convert(String::from("PAYPALISHIRING"), 3),
            String::from("PAHNAPLSIIGYIR")
        );
        assert_eq!(
            Solution::convert(String::from("PAYPALISHIRING"), 4),
            String::from("PINALSIGYAHRPI")
        );
    }
}
