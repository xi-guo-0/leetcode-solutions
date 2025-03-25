struct Solution;

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut res: i32 = 0;
        let mut cur: i32 = x;

        while cur != 0 {
            match res.checked_mul(10) {
                None => return 0,
                Some(tmp) => match tmp.checked_add(cur % 10) {
                    None => return 0,
                    Some(fine) => {
                        res = fine;
                    }
                },
            }
            cur = cur / 10;
        }
        res
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_reverse() {
        assert_eq!(Solution::reverse(123), 321);
        assert_eq!(Solution::reverse(-123), -321);
        assert_eq!(Solution::reverse(120), 21);
    }
}
