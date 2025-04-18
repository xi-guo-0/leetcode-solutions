fn is_vowel_substring(s: &str) -> bool {
    let mut oc = [false; 128];
    let vowels = "aeiou";
    for c in s.chars() {
        if !vowels.contains(c) {
            return false;
        }
        oc[c as usize] = true;
    }
    for vowel in vowels.chars() {
        if !oc[vowel as usize] {
            return false;
        }
    }
    true
}

impl Solution {
    pub fn count_vowel_substrings(word: String) -> i32 {
        let mut ans = 0;
        for i in 0..word.len() {
            for j in (i + 5)..=word.len() {
                if (is_vowel_substring(&word[i..j])) {
                    ans += 1;
                }
            }
        }
        ans
    }
}
