fn is_vowel(c: char) -> bool {
    "aeiou".contains(c)
}

fn is_vowel_string(s: &String) -> bool {
    is_vowel(s.chars().nth(0).unwrap()) && is_vowel(s.chars().nth(s.len() - 1).unwrap())
}

impl Solution {
    pub fn vowel_strings(words: Vec<String>, left: i32, right: i32) -> i32 {
        words[(left as usize)..(right as usize + 1)]
            .iter()
            .filter(|s| is_vowel_string(s))
            .count() as i32
    }
}
