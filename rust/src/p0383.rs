struct Solution;

impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut oc = [0; 26];
        for ch in magazine.chars().into_iter() {
            oc[ch as usize - 'a' as usize] += 1;
        }
        for ch in ransom_note.chars().into_iter() {
            oc[ch as usize - 'a' as usize] -= 1;
        }
        oc.into_iter().all(|cnt| 0 <= cnt)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_can_construct() {
        assert!(!Solution::can_construct("a".to_string(), "b".to_string()));
        assert!(!Solution::can_construct("aa".to_string(), "ab".to_string()));
        assert!(Solution::can_construct("aa".to_string(), "aab".to_string()));
    }
}
