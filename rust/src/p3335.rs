struct Solution;

impl Solution {
    pub fn length_after_transformations(s: String, t: i32) -> i32 {
        const MOD: i32 = 1_000_000_007;
        let mut freq = [0; 26];
        for ch in s.chars() {
            freq[(ch as u8 - b'a') as usize] += 1;
        }
        for _ in 0..t {
            let mut new_freq = [0; 26];
            for i in 0..26 {
                if i == 25 {
                    new_freq[0] = (new_freq[0] + freq[i]) % MOD;
                    new_freq[1] = (new_freq[1] + freq[i]) % MOD;
                } else {
                    new_freq[i + 1] = (new_freq[i + 1] + freq[i]) % MOD;
                }
            }
            freq = new_freq;
        }
        freq.iter().fold(0, |acc, &x| (acc + x) % MOD)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_length_after_transformations() {
        assert_eq!(
            Solution::length_after_transformations(String::from("abcyy"), 2),
            7
        );
        assert_eq!(
            Solution::length_after_transformations(String::from("azbk"), 1),
            5
        );
    }
}
