struct Solution;

impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        if digits.is_empty() {
            return Vec::new();
        }
        let digit_to_letters = [
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
        ];
        let mut combinations = Vec::new();
        let mut current_combination = String::new();
        Self::backtrack(
            0,
            &digits,
            &digit_to_letters,
            &mut combinations,
            &mut current_combination,
        );
        combinations
    }

    fn backtrack(
        position: usize,
        digits: &str,
        digit_to_letters: &[&str],
        combinations: &mut Vec<String>,
        current_combination: &mut String,
    ) {
        if position == digits.len() {
            combinations.push(current_combination.clone());
            return;
        }
        let digit = digits.chars().nth(position).unwrap().to_digit(10).unwrap() as usize;
        for letter in digit_to_letters[digit].chars() {
            current_combination.push(letter);
            Self::backtrack(
                position + 1,
                digits,
                digit_to_letters,
                combinations,
                current_combination,
            );
            current_combination.pop();
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_letter_combinations() {
        assert_eq!(
            Solution::letter_combinations(String::from("23")),
            vec!["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
        );
        assert_eq!(
            Solution::letter_combinations(String::from("")),
            Vec::<String>::new()
        );
        assert_eq!(
            Solution::letter_combinations(String::from("2")),
            vec!["a", "b", "c"]
        );
    }
}
