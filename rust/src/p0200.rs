pub fn dfs(grid: &mut Vec<Vec<char>>, r: i32, c: i32) {
    let land = '1';
    let water = '0';
    let dirs = [(-1, 0), (0, -1), (1, 0), (0, 1)];
    grid[r as usize][c as usize] = water;
    for d in dirs {
        let nr = r + d.0;
        let nc = c + d.1;
        if 0 <= nr
            && nr < (grid.len() as i32)
            && 0 <= nc
            && nc < (grid[0].len() as i32)
            && grid[nr as usize][nc as usize] == land
        {
            dfs(grid, nr, nc);
        }
    }
}

impl Solution {
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        let land = '1';
        let mut ans = 0;
        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                if grid[i][j] == land {
                    ans += 1;
                    dfs(&mut grid, i as i32, j as i32);
                }
            }
        }
        ans
    }
}
