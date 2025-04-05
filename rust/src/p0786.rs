use std::cmp::Ordering;

struct Solution;

impl Solution {
    pub fn kth_smallest_prime_fraction(arr: Vec<i32>, k: i32) -> Vec<i32> {
        let n = arr.len();
        let mut fractions = Vec::with_capacity(n * (n - 1) / 2);
        for i in 0..n {
            for j in i + 1..n {
                fractions.push((arr[i] as f64 / arr[j] as f64, arr[i], arr[j]));
            }
        }
        fractions.sort_by(|a, b| a.partial_cmp(&b).unwrap_or(Ordering::Equal));
        let (_, numerator, denominator) = fractions[(k - 1) as usize];
        vec![numerator, denominator]
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_kth_smallest_prime_fraction() {
        assert_eq!(
            Solution::kth_smallest_prime_fraction(vec![1, 2, 3, 5], 3),
            vec![2, 5]
        );
        assert_eq!(
            Solution::kth_smallest_prime_fraction(vec![1, 7], 1),
            vec![1, 7]
        );
    }
}
