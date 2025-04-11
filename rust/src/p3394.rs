struct Solution;

impl Solution {
    pub fn check_valid_cuts(n: i32, mut rectangles: Vec<Vec<i32>>) -> bool {
        Self::has_valid_cut(&rectangles, 0) >= 3 || Self::has_valid_cut(&rectangles, 1) >= 3
    }

    fn has_valid_cut(rectangles: &[Vec<i32>], dimension: usize) -> i32 {
        let mut sorted_rectangles = rectangles.to_vec();
        sorted_rectangles.sort_by_key(|item| item[dimension]);

        sorted_rectangles
            .iter()
            .skip(1)
            .fold(
                (
                    1,
                    sorted_rectangles[0][dimension],
                    sorted_rectangles[0][dimension + 2],
                ),
                |(cuts, prev_start, prev_end), item| {
                    if item[dimension] >= prev_start && item[dimension] < prev_end {
                        (cuts, prev_start, prev_end.max(item[dimension + 2]))
                    } else {
                        (cuts + 1, item[dimension], item[dimension + 2])
                    }
                },
            )
            .0
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_check_valid_cuts() {
        assert!(Solution::check_valid_cuts(
            5,
            vec![
                vec![1, 0, 5, 2],
                vec![0, 2, 2, 4],
                vec![3, 2, 5, 3],
                vec![0, 4, 4, 5]
            ]
        ));
        assert!(Solution::check_valid_cuts(
            4,
            vec![
                vec![0, 0, 1, 1],
                vec![2, 0, 3, 4],
                vec![0, 2, 2, 3],
                vec![3, 0, 4, 3]
            ]
        ));
        assert!(!Solution::check_valid_cuts(
            4,
            vec![
                vec![0, 2, 2, 4],
                vec![1, 0, 3, 2],
                vec![2, 2, 3, 4],
                vec![3, 0, 4, 2],
                vec![3, 2, 4, 4]
            ]
        ));
    }
}
