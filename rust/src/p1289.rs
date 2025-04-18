use std::mem::swap;

impl Solution {
    pub fn min_falling_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut dp0 = grid[0].clone();
        let mut dp1 = vec![0i32; n];
        let mut dai: Vec<(i32, usize)> = vec![(0i32, 0usize); n];
        for i in 1..n {
            for j in 0..n {
                dai[j] = (dp0[j], j);
            }
            dai.sort();
            for j in 0..n {
                let mut k = 0;
                while dai[k].1 == j {
                    k += 1;
                }
                dp1[j] = dai[k].0 + grid[i][j];
            }
            swap(&mut dp0, &mut dp1);
        }
        dp0.into_iter().min().unwrap()
    }
}
