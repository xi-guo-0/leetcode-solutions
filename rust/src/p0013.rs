struct Solution;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let s: Vec<char> = s.chars().collect();
        let mut ans = 0i32;
        for i in 0..s.len() {
            if 0 < i && Self::c_to_i32(s[i]) > Self::c_to_i32(s[i - 1]) {
                ans += Self::c_to_i32(s[i]) - 2 * Self::c_to_i32(s[i - 1]);
            } else {
                ans += Self::c_to_i32(s[i]);
            }
        }
        ans
    }
    fn c_to_i32(c: char) -> i32 {
        match c {
            'I' => 1,
            'V' => 5,
            'X' => 10,
            'L' => 50,
            'C' => 100,
            'D' => 500,
            'M' => 1000,
            _ => 0,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_roman_to_int() {
        assert_eq!(Solution::roman_to_int(String::from("III")), 3);
        assert_eq!(Solution::roman_to_int(String::from("LVIII")), 58);
        assert_eq!(Solution::roman_to_int(String::from("MCMXCIV")), 1994);
    }
}
