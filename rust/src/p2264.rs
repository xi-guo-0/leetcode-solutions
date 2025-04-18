impl Solution {
    pub fn largest_good_integer(num: String) -> String {
        let num: Vec<_> = num
            .chars()
            .map(|c| c.to_digit(10).unwrap() as i32)
            .collect();
        let mut d = -1;
        for i in 2..num.len() {
            let t = num[i];
            if t == num[i - 1] && t == num[i - 2] && d < t {
                d = t;
            }
        }
        if d < 0 {
            "".to_string()
        } else {
            let s = d.to_string();
            format!("{}{}{}", s, s, s)
        }
    }
}
