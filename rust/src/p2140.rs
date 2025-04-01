struct Solution;

impl Solution {
    pub fn most_points(questions: Vec<Vec<i32>>) -> i64 {
        let n = questions.len();
        let mut dp = vec![0; n];
        for i in (0..n).rev() {
            let (points, brainpower) = (questions[i][0] as i64, questions[i][1] as i64);
            let next_question = i + brainpower as usize + 1;
            let solve = points
                + if next_question < n {
                    dp[next_question]
                } else {
                    0
                };
            let skip = if i + 1 < n { dp[i + 1] } else { 0 };
            dp[i] = solve.max(skip);
        }
        dp[0]
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_most_points() {
        assert_eq!(
            Solution::most_points(vec![vec![3, 2], vec![4, 3], vec![4, 4], vec![2, 5]]),
            5
        );
        assert_eq!(
            Solution::most_points(vec![
                vec![1, 1],
                vec![2, 2],
                vec![3, 3],
                vec![4, 4],
                vec![5, 5]
            ]),
            7
        );
    }
}
