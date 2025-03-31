struct Solution;

impl Solution {
    pub fn divide(dividend: i32, divisor: i32) -> i32 {
        fn subtract_loop(dividend: i64, divisor: i64, quotient: i64) -> i64 {
            if dividend < divisor {
                quotient
            } else {
                let mut current = divisor;
                let mut multiple = 1;
                while current + current <= dividend {
                    current += current;
                    multiple += multiple;
                }
                subtract_loop(dividend - current, divisor, quotient + multiple)
            }
        }
        if dividend == i32::MIN && divisor == -1 {
            return i32::MAX;
        }
        let negative = (dividend < 0) != (divisor < 0);
        let dividend = (dividend as i64).abs();
        let divisor = (divisor as i64).abs();
        let result = subtract_loop(dividend, divisor, 0);
        if negative {
            (-result) as i32
        } else {
            result as i32
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_divide() {
        assert_eq!(Solution::divide(10, 3), 3);
        assert_eq!(Solution::divide(7, -3), -2);
    }
}
