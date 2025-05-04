use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32 {
        let mut count = HashMap::new();
        let mut ans = 0;
        for d in dominoes {
            let key = if d[0] <= d[1] {
                (d[0], d[1])
            } else {
                (d[1], d[0])
            };
            let c = count.entry(key).or_insert(0);
            ans += *c;
            *c += 1;
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_num_equiv_domino_pairs() {
        let dominoes = vec![vec![1, 2], vec![2, 1], vec![3, 4], vec![5, 6]];
        assert_eq!(Solution::num_equiv_domino_pairs(dominoes), 1);
        let dominoes = vec![vec![1, 2], vec![1, 2], vec![1, 1], vec![1, 2], vec![2, 2]];
        assert_eq!(Solution::num_equiv_domino_pairs(dominoes), 3);
    }
}
