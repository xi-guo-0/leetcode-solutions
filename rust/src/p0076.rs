struct Solution;

impl Solution {
    pub fn min_window(s: String, t: String) -> String {
        let mut freq = vec![0; 128];
        for b in t.bytes() {
            freq[b as usize] += 1;
        }
        let (mut i, mut r, mut c) = (0, 0..0, t.len());
        for (j, b) in s.bytes().enumerate() {
            if freq[b as usize] > 0 {
                c -= 1;
            }
            freq[b as usize] -= 1;
            while c == 0 {
                if j - i + 1 < r.len() || r.len() == 0 {
                    r = i..j + 1;
                }
                let a = s.as_bytes()[i] as usize;
                freq[a] += 1;
                if freq[a] > 0 {
                    c += 1;
                }
                i += 1;
            }
        }
        s[r].into()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_min_window() {
        assert_eq!(
            Solution::min_window(String::from("ADOBECODEBANC"), String::from("ABC")),
            "BANC"
        );
        assert_eq!(
            Solution::min_window(String::from("a"), String::from("a")),
            "a"
        );
        assert_eq!(
            Solution::min_window(String::from("a"), String::from("aa")),
            ""
        );
    }
}
