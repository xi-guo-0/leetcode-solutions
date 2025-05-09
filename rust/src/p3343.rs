struct Solution;

impl Solution {
    pub fn count_balanced_permutations(num: String) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let velunexorai = num.clone();
        let n = velunexorai.len();
        let mut freq = [0; 10];
        for ch in velunexorai.chars() {
            let d = ch.to_digit(10).unwrap() as usize;
            freq[d] += 1;
        }
        let total_sum: i64 = (0..10).map(|d| d as i64 * freq[d] as i64).sum();
        if total_sum % 2 != 0 {
            return 0;
        }
        let target = (total_sum / 2) as usize;
        let n_even = if n % 2 == 0 { n / 2 } else { n / 2 + 1 };
        let n_odd = n - n_even;
        let (fact, inv_fact) = Self::precompute_factorials(n + 1, MOD);
        Self::dp_solution(&freq, n_even, n_odd, target, n, MOD, &fact, &inv_fact)
    }

    fn dp_solution(
        freq: &[usize; 10],
        n_even: usize,
        n_odd: usize,
        target: usize,
        n: usize,
        mod_v: i64,
        fact: &[i64],
        inv_fact: &[i64],
    ) -> i32 {
        let mut dp = vec![vec![vec![0; target + 1]; n_even + 1]; 11];
        dp[0][0][0] = 1;
        for d in 0..10 {
            let cnt = freq[d];
            if cnt == 0 {
                for j in 0..=n_even {
                    for s in 0..=target {
                        dp[d + 1][j][s] = dp[d][j][s];
                    }
                }
                continue;
            }
            for j in 0..=n_even {
                for s in 0..=target {
                    let cur = dp[d][j][s];
                    if cur == 0 {
                        continue;
                    }
                    let max_x = std::cmp::min(cnt, n_even - j);
                    for x in 0..=max_x {
                        let new_j = j + x;
                        let new_sum = s + d * x;
                        if new_sum > target {
                            continue;
                        }
                        let mult = (inv_fact[x] * inv_fact[cnt - x]) % mod_v;
                        dp[d + 1][new_j][new_sum] =
                            (dp[d + 1][new_j][new_sum] + cur * mult) % mod_v;
                    }
                }
            }
        }
        let res = dp[10][n_even][target];
        let result = (res * fact[n_even]) % mod_v;
        let result = (result * fact[n_odd]) % mod_v;
        result as i32
    }

    fn precompute_factorials(n: usize, mod_v: i64) -> (Vec<i64>, Vec<i64>) {
        let mut fact = vec![1; n];
        for i in 1..n {
            fact[i] = fact[i - 1] * (i as i64) % mod_v;
        }
        let mut inv_fact = vec![1; n];
        inv_fact[n - 1] = Self::mod_pow(fact[n - 1], mod_v - 2, mod_v);
        for i in (0..n - 1).rev() {
            inv_fact[i] = inv_fact[i + 1] * ((i + 1) as i64) % mod_v;
        }
        (fact, inv_fact)
    }

    fn mod_pow(mut a: i64, mut b: i64, mod_v: i64) -> i64 {
        let mut res = 1;
        a %= mod_v;
        while b > 0 {
            if b % 2 == 1 {
                res = res * a % mod_v;
            }
            a = a * a % mod_v;
            b /= 2;
        }
        res
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_count_balanced_permutations() {
        assert_eq!(
            Solution::count_balanced_permutations(String::from("123")),
            2
        );
        assert_eq!(
            Solution::count_balanced_permutations(String::from("112")),
            1
        );
        assert_eq!(
            Solution::count_balanced_permutations(String::from("12345")),
            0
        );
    }
}
