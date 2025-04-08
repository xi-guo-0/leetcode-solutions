use std::collections::BinaryHeap;

struct Solution;

impl Solution {
    pub fn find_relative_ranks(score: Vec<i32>) -> Vec<String> {
        let mut sorted_indices = BinaryHeap::new();
        score
            .iter()
            .enumerate()
            .for_each(|(i, &score)| sorted_indices.push((score, i)));

        let mut res = vec![String::new(); score.len()];
        let mut curr = 1;

        while let Some((_, i)) = sorted_indices.pop() {
            let placement = match curr {
                1 => "Gold Medal".to_string(),
                2 => "Silver Medal".to_string(),
                3 => "Bronze Medal".to_string(),
                n => n.to_string(),
            };

            res[i] = placement;
            curr += 1
        }

        res
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_find_relative_ranks() {
        assert_eq!(
            Solution::find_relative_ranks(vec![5, 4, 3, 2, 1]),
            ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
        );
        assert_eq!(
            Solution::find_relative_ranks(vec![10, 3, 8, 9, 4]),
            ["Gold Medal", "5", "Bronze Medal", "Silver Medal", "4"]
        );
    }
}
