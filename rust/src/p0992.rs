struct Solution;

impl Solution {
    pub fn subarrays_with_k_distinct(nums: Vec<i32>, k: i32) -> i32 {
        nums.iter()
            .fold(
                (
                    vec![0; nums.len() + 1],
                    vec![0; nums.len() + 1],
                    0,
                    0,
                    0,
                    0,
                    0,
                ),
                |(mut m, mut m1, mut n, mut n1, mut i, mut i1, ans), &x| {
                    let x = x as usize;
                    m[x] += 1;
                    m1[x] += 1;
                    if m[x] == 1 {
                        n += 1;
                    }
                    if m1[x] == 1 {
                        n1 += 1;
                    }

                    while n > k {
                        let num = nums[i] as usize;
                        m[num] -= 1;
                        if m[num] == 0 {
                            n -= 1;
                        }
                        i += 1;
                    }
                    while n1 >= k {
                        let num = nums[i1] as usize;
                        m1[num] -= 1;
                        if m1[num] == 0 {
                            n1 -= 1;
                        }
                        i1 += 1;
                    }
                    (m, m1, n, n1, i, i1, ans + i1 - i)
                },
            )
            .6 as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_subarrays_with_k_distinct() {
        assert_eq!(
            Solution::subarrays_with_k_distinct(vec![1, 2, 1, 2, 3], 2),
            7
        );
        assert_eq!(
            Solution::subarrays_with_k_distinct(vec![1, 2, 1, 3, 4], 3),
            3
        );
    }
}
