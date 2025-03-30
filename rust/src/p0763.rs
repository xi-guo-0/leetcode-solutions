struct Solution;

impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        let last_occur = Self::last_occur(&s);
        let mut ans = Vec::new();
        let mut i = 0;

        while i < s.len() {
            let aim = s.as_bytes()[i] as usize;
            let mut right = last_occur[aim];
            let mut j = i + 1;

            while j < right {
                right = right.max(last_occur[s.as_bytes()[j] as usize]);
                j += 1;
            }

            ans.push((right - i + 1) as i32);
            i = right + 1;
        }
        ans
    }

    fn last_occur(s: &str) -> Vec<usize> {
        let mut ans = vec![0; 128];
        for (i, &c) in s.as_bytes().iter().enumerate() {
            ans[c as usize] = i;
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_reverse_k_group() {
        assert_eq!(
            Solution::partition_labels(String::from("ababcbacadefegdehijhklij")),
            vec![9, 7, 8]
        );
        assert_eq!(
            Solution::partition_labels(String::from("eccbbbbdec")),
            vec![10]
        );
    }
}
