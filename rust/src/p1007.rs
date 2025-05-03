struct Solution;

impl Solution {
    pub fn min_domino_rotations(tops: Vec<i32>, bottoms: Vec<i32>) -> i32 {
        let n = tops.len();
        let first_top = tops[0];
        let first_bottom = bottoms[0];
        let candidates = if first_top == first_bottom {
            vec![first_top]
        } else {
            vec![first_top, first_bottom]
        };
        fn rotations_to_make_row_equal(
            target: i32,
            row1: &Vec<i32>,
            row2: &Vec<i32>,
        ) -> Option<i32> {
            let mut rotations = 0;
            for i in 0..row1.len() {
                if row1[i] == target {
                    continue;
                } else if row2[i] == target {
                    rotations += 1;
                } else {
                    return None;
                }
            }
            Some(rotations)
        }
        let mut min_rot = std::i32::MAX;
        for x in candidates {
            if let Some(rot_top) = rotations_to_make_row_equal(x, &tops, &bottoms) {
                min_rot = std::cmp::min(min_rot, rot_top);
            }
            if let Some(rot_bot) = rotations_to_make_row_equal(x, &bottoms, &tops) {
                min_rot = std::cmp::min(min_rot, rot_bot);
            }
        }
        if min_rot != std::i32::MAX {
            min_rot
        } else {
            -1
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_min_domino_rotations() {
        assert_eq!(
            Solution::min_domino_rotations(vec![2, 1, 2, 4, 2, 2], vec![5, 2, 6, 2, 3, 2]),
            2
        );
        assert_eq!(
            Solution::min_domino_rotations(vec![3, 5, 1, 2, 3], vec![3, 6, 3, 3, 4]),
            -1
        );
    }
}
