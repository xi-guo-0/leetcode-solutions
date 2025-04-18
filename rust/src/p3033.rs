impl Solution {
    pub fn modified_matrix(mut matrix: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut maximum = vec![-1; n];
        for i in 0..m {
            for j in 0..n {
                maximum[j] = std::cmp::max(maximum[j], matrix[i][j]);
            }
        }
        for i in 0..m {
            for j in 0..n {
                if matrix[i][j] == -1 {
                    matrix[i][j] = maximum[j];
                }
            }
        }
        matrix
    }
}
