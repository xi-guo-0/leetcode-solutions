impl Solution {
    pub fn alternate_digit_sum(n: i32) -> i32 {
        let digits: Vec<_> = n
            .to_string()
            .chars()
            .map(|c| c.to_digit(10).unwrap() as i32)
            .collect();
        let mut ans = 0;
        let mut sign = true;
        for d in digits {
            if sign {
                ans += d;
            } else {
                ans -= d;
            }
            sign = !sign;
        }
        ans
    }
}
