struct Solution;

impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let mut num = num;
        let radix = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
        let symbol = [
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
        ];
        let mut ans = String::new();
        let mut i: usize = 0;
        while 0 < num {
            let count = num / radix[i];
            num %= radix[i];
            for j in 0..count {
                ans.push_str(symbol[i as usize]);
            }
            i += 1;
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_int_to_roman() {
        assert_eq!(Solution::int_to_roman(3749), "MMMDCCXLIX");
        assert_eq!(Solution::int_to_roman(58), "LVIII");
        assert_eq!(Solution::int_to_roman(1994), "MCMXCIV");
    }
}
