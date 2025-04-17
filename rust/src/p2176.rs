use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn count_pairs(nums: Vec<i32>, k: i32) -> i32 {
        let groups = Self::group_indices_by_value(&nums);
        let mut count = 0;
        for indices in groups {
            if indices.len() < 2 {
                continue;
            }
            for i in 0..indices.len() {
                for j in i + 1..indices.len() {
                    let idx_i = indices[i] as i32;
                    let idx_j = indices[j] as i32;
                    if (idx_i * idx_j) % k == 0 {
                        count += 1;
                    }
                }
            }
        }
        count
    }

    fn group_indices_by_value<T: Eq + std::hash::Hash>(slice: &[T]) -> Vec<Vec<usize>> {
        let mut groups = HashMap::with_capacity(slice.len());
        for (index, value) in slice.iter().enumerate() {
            groups.entry(value).or_insert_with(Vec::new).push(index);
        }
        let mut result: Vec<_> = groups.into_values().collect();
        result.sort_unstable_by_key(|v| v[0]);
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_count_pairs() {
        assert_eq!(Solution::count_pairs(vec![3, 1, 2, 2, 2, 1, 3], 2), 4);
        assert_eq!(Solution::count_pairs(vec![1, 2, 3, 4], 1), 0);
    }
}
