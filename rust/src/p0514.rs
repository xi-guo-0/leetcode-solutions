use std::cmp::max;
use std::cmp::min;

struct Solution;

impl Solution {
    pub fn find_rotate_steps(ring: String, key: String) -> i32 {
        Self::helper(ring.chars().collect(), key.chars().collect()) as i32
    }

    fn helper(ring: Vec<char>, key: Vec<char>) -> usize {
        let n = ring.len();
        let mut dp0 = vec![0; n];
        for i in 0..n {
            dp0[i] = std::cmp::min(i, n - i);
        }
        for c in key.into_iter() {
            let mut dp1 = vec![usize::MAX / 2; n];
            for i in 0..n {
                for j in 0..n {
                    let l = min(i, j);
                    let r = max(i, j);
                    let inner = ring[l..=r].contains(&c);
                    let outer = ring[0..=l].contains(&c) || ring[r..n].contains(&c);
                    if inner && outer {
                        dp1[j] = min(dp1[j], min(dp0[i] + 1 + r - l, dp0[i] + 1 + n - r + l));
                    } else if inner {
                        dp1[j] = min(dp1[j], dp0[i] + 1 + r - l);
                    } else {
                        dp1[j] = min(dp1[j], dp0[i] + 1 + n - r + l);
                    }
                }
            }
            dp0 = dp1;
        }
        dp0.into_iter().min().unwrap()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_find_rotate_steps() {
        assert_eq!(
            Solution::find_rotate_steps(String::from("godding"), String::from("gd")),
            4
        );
        assert_eq!(
            Solution::find_rotate_steps(String::from("godding"), String::from("godding")),
            13
        );
    }
}
