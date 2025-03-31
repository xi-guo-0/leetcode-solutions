struct Solution;

impl Solution {
    pub fn put_marbles(weights: Vec<i32>, k: i32) -> i64 {
        if weights.is_empty() {
            return 0;
        }
        let k = k as usize;
        let n = weights.len();
        let mut weight_pairs: Vec<u64> = weights
            .windows(2)
            .map(|pair| (pair[0] + pair[1]) as u64)
            .collect();
        weight_pairs.sort_unstable();
        let largest_sum: u64 = weight_pairs.iter().rev().take(k - 1).sum();
        let smallest_sum: u64 = weight_pairs.iter().take(k - 1).sum();
        (largest_sum - smallest_sum) as i64
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_put_marbles() {
        assert_eq!(Solution::put_marbles(vec![1, 3, 5, 1], 2), 4);
        assert_eq!(Solution::put_marbles(vec![1, 3], 2), 0);
    }
}
