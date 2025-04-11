struct Solution;

impl Solution {
    pub fn count_symmetric_integers(low: i32, high: i32) -> i32 {
        let mut ans = 0;
        for n in low..(high + 1) {
            if Self::digits_len(n) % 2 == 0 && Self::is_symmetric(n) {
                ans += 1;
            }
        }
        ans
    }

    fn digits_len(n: i32) -> i32 {
        return n.to_string().len() as i32;
    }

    fn digits_sum(mut n: i32) -> i32 {
        let mut ans = 0;
        while n > 0 {
            ans += n % 10;
            n /= 10;
        }
        ans
    }

    fn is_symmetric(n: i32) -> bool {
        let l = Self::digits_len(n);
        let mut t = n;
        for _ in 0..(l / 2) {
            t /= 10;
        }
        let left = t;
        for _ in 0..(l / 2) {
            t *= 10;
        }
        let right = n - t;
        Self::digits_sum(left) == Self::digits_sum(right)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_count_symmetric_integers() {
        assert_eq!(Solution::count_symmetric_integers(1, 100), 9);
        assert_eq!(Solution::count_symmetric_integers(1200, 1230), 4);
    }
}
