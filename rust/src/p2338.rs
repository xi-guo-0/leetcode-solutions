struct Solution;

impl Solution {
    pub fn ideal_arrays(n: i32, max_value: i32) -> i32 {
        let m: i32 = 1_000_000_007;
        let n = n as usize;
        let max_val = max_value as usize;
        if max_val == 0 {
            return 0;
        }

        let mut spf = vec![0; max_val + 1];
        spf[0] = 0;
        spf[1] = 1;
        for i in 2..=max_val {
            if spf[i] == 0 {
                spf[i] = i;
                let mut j = i * 2;
                while j <= max_val {
                    if spf[j] == 0 {
                        spf[j] = i;
                    }
                    j += i;
                }
            }
        }

        let a_max = n + max_val;
        let mut factorial = vec![1i64; a_max + 1];
        for i in 1..=a_max {
            factorial[i] = (factorial[i - 1] * i as i64) % m as i64;
        }

        let mut inv_fact = vec![1i64; a_max + 1];
        inv_fact[a_max] = Self::pow_mod(factorial[a_max], (m - 2) as i64, m as i64);
        for i in (0..a_max).rev() {
            inv_fact[i] = (inv_fact[i + 1] * (i + 1) as i64) % m as i64;
        }

        let inv_fact_n2 = if n >= 2 { inv_fact[n - 2] } else { 0 };

        let mut total = 0i64;
        for k in 1..=max_val {
            let mut fk = 1i64;
            if k != 1 {
                let mut x = k;
                let mut exponents = Vec::new();
                while x != 1 {
                    let p = spf[x];
                    let mut cnt = 0;
                    while x % p == 0 {
                        cnt += 1;
                        x /= p;
                    }
                    exponents.push(cnt);
                }
                for e in exponents {
                    let a = e + (n - 2);
                    let comb = (factorial[a] * inv_fact[e] % m as i64) * inv_fact_n2 % m as i64;
                    fk = fk * comb % m as i64;
                }
            }
            let count = (max_val / k) as i64;
            total = (total + fk * count) % m as i64;
        }

        total as i32
    }

    fn pow_mod(mut x: i64, mut p: i64, m: i64) -> i64 {
        let mut res = 1;
        x %= m;
        while p > 0 {
            if p % 2 == 1 {
                res = (res * x) % m;
            }
            x = (x * x) % m;
            p /= 2;
        }
        res
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_ideal_arrays() {
        assert_eq!(Solution::ideal_arrays(2, 5), 10);
        assert_eq!(Solution::ideal_arrays(5, 3), 11);
    }
}
