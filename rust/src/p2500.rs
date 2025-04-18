impl Solution {
    pub fn delete_greatest_value(mut grid: Vec<Vec<i32>>) -> i32 {
        grid.iter_mut().for_each(|mut row| row.sort_unstable());
        (0..grid[0].len()).fold(0, |mut res, col| {
            res += grid
                .iter()
                .fold(0, |maxi, vecs| std::cmp::max(maxi, vecs[col]));
            res
        })
    }
}
