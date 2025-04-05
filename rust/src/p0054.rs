struct Solution;

impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let m = matrix.len();
        let n = matrix[0].len();
        let l = std::cmp::min(m, n);
        let mut li = m;
        let mut lj = n;
        let mut ans = Vec::<i32>::new();
        for frame in 0..l / 2 {
            for j in frame..lj - 1 {
                ans.push(matrix[frame][j]);
            }
            for i in frame..li - 1 {
                ans.push(matrix[i][lj - 1]);
            }
            for j in (frame + 1..lj).rev() {
                ans.push(matrix[li - 1][j]);
            }
            for i in (frame + 1..li).rev() {
                ans.push(matrix[i][frame]);
            }
            li -= 1;
            lj -= 1;
        }
        if m <= n && m & 1 == 1 {
            for j in m / 2..lj {
                ans.push(matrix[m / 2][j]);
            }
        } else if n & 1 == 1 {
            for i in n / 2..li {
                ans.push(matrix[i][n / 2]);
            }
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_spiral_order() {
        assert_eq!(
            Solution::spiral_order(vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]]),
            vec![1, 2, 3, 6, 9, 8, 7, 4, 5]
        );
        assert_eq!(
            Solution::spiral_order(vec![
                vec![1, 2, 3, 4],
                vec![5, 6, 7, 8],
                vec![9, 10, 11, 12]
            ]),
            vec![1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
        );
    }
}
