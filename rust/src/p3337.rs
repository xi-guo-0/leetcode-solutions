struct Solution;

impl Solution {
    pub fn length_after_transformations(s: String, t: i32, nums: Vec<i32>) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let mut counts = vec![0; 26];
        for c in s.chars() {
            counts[(c as u8 - b'a') as usize] += 1;
        }
        let mut M = vec![vec![0; 26]; 26];
        for i in 0..26 {
            let start = ((i as i32 + 1) % 26) as i32;
            let l = nums[i] as i32;
            for j in 0..26 {
                let dist = ((j as i32 - start + 26) % 26) as i32;
                if dist < l {
                    M[i][j] = 1;
                } else {
                    M[i][j] = 0;
                }
            }
        }
        let M_power = Self::matrix_power(&M, t as i64, MOD as i64);
        let mut res = 0;
        for j in 0..26 {
            let mut sum_j = 0;
            for i in 0..26 {
                sum_j = (sum_j + (counts[i] as i64) * M_power[i][j]) % MOD;
            }
            res = (res + sum_j) % MOD;
        }
        res as i32
    }

    fn matrix_power(mat: &Vec<Vec<i64>>, power: i64, mod_val: i64) -> Vec<Vec<i64>> {
        let n = mat.len();
        let mut result = vec![vec![0; n]; n];
        for i in 0..n {
            result[i][i] = 1;
        }
        let mut base = mat.clone();
        let mut exp = power;
        while exp > 0 {
            if exp % 2 == 1 {
                result = Self::multiply(&result, &base, mod_val);
            }
            base = Self::multiply(&base, &base, mod_val);
            exp /= 2;
        }
        result
    }

    fn multiply(a: &Vec<Vec<i64>>, b: &Vec<Vec<i64>>, mod_val: i64) -> Vec<Vec<i64>> {
        let n = a.len();
        let mut result = vec![vec![0; n]; n];
        for i in 0..n {
            for k in 0..n {
                if a[i][k] == 0 {
                    continue;
                }
                for j in 0..n {
                    result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % mod_val;
                }
            }
        }
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_length_after_transformations() {
        assert_eq!(
            Solution::length_after_transformations(
                String::from("abcyy"),
                2,
                vec![
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2
                ]
            ),
            7
        );
        assert_eq!(
            Solution::length_after_transformations(
                String::from("azbk"),
                1,
                vec![
                    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
                ]
            ),
            8
        );
    }
}
