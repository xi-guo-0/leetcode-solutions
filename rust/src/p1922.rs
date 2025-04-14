struct Solution;

impl Solution {
    pub fn count_good_numbers(n: i64) -> i32 {
        let mod_val: i64 = 1_000_000_007;
        let event_count = (n + 1) / 2;
        let odd_count = n / 2;
        let pow5 = Self::pow_mod(5, event_count, mod_val);
        let pow4 = Self::pow_mod(4, odd_count, mod_val);
        ((pow5 * pow4) % mod_val) as i32
    }

    fn pow_mod(mut a: i64, mut b: i64, mod_val: i64) -> i64 {
        let mut res = 1;
        a %= mod_val;
        while 0 < b {
            if b % 2 == 1 {
                res = (res * a) % mod_val;
            }
            a = (a * a) % mod_val;
            b /= 2;
        }
        res
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_count_good_numbers() {
        assert_eq!(Solution::count_good_numbers(1), 5);
        assert_eq!(Solution::count_good_numbers(4), 400);
        assert_eq!(Solution::count_good_numbers(50), 564908303);
    }
}
