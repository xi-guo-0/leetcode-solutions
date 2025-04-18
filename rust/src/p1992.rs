impl Solution {
    pub fn find_farmland(mut land: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = Vec::new();
        let m = land.len();
        let n = land[0].len();
        for i in 0..m {
            for j in 0..n {
                if land[i][j] == 1 {
                    let mut x = i;
                    let mut y = j;
                    while x < m && land[x][j] == 1 {
                        y = j;
                        while y < n && land[x][y] == 1 {
                            land[x][y] = 0;
                            y += 1;
                        }
                        x += 1;
                    }
                    ans.push(vec![i as i32, j as i32, x as i32 - 1, y as i32 - 1]);
                }
            }
        }
        ans
    }
}
