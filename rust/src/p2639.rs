impl Solution {
    pub fn find_column_width(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let m = grid.len();
        let n = grid[0].len();
        let mut ans = vec![0 as i32; n];
        for row in grid.into_iter() {
            for j in 0..n {
                let mut width = 1;
                let mut num = row[j];
                if row[j] < 0 {
                    width += 1;
                }
                num /= 10;
                while 0 != num {
                    width += 1;
                    num /= 10;
                }
                ans[j] = std::cmp::max(ans[j], width as i32);
            }
        }
        ans
    }
}
