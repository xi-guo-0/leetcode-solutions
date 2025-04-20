use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn num_rabbits(answers: Vec<i32>) -> i32 {
        let mut count_map = HashMap::new();
        for &ans in &answers {
            *count_map.entry(ans + 1).or_insert(0) += 1;
        }
        let mut total = 0;
        for (&group_size, &count) in count_map.iter() {
            let groups_needed = (count + group_size - 1) / group_size;
            total += groups_needed * group_size;
        }
        total
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_num_rabbits() {
        assert_eq!(Solution::num_rabbits(vec![1, 1, 2]), 5);
        assert_eq!(Solution::num_rabbits(vec![10, 10, 10]), 11);
    }
}
