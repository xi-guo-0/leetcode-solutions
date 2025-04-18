fn i32_to_digits(n: i32) -> Vec<i32> {
    n.to_string()
        .chars()
        .map(|c| c.to_digit(10).unwrap() as i32)
        .collect()
}

impl Solution {
    pub fn split_num(num: i32) -> i32 {
        let mut digits = i32_to_digits(num);

        digits.sort_by(|a, b| b.cmp(a));
        if digits.len() % 2 != 0 {
            digits.push(0);
        }
        let mut ans = 0;
        for i in (0..digits.len()).step_by(2).rev() {
            ans = ans * 10 + digits[i] + digits[i + 1]
        }
        ans
    }
}
