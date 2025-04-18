impl Solution {
    pub fn game_of_life(board: &mut Vec<Vec<i32>>) {
        let m = board.len() as i32;
        let n = board[0].len() as i32;
        for i in 0..m {
            for j in 0..n {
                let neighbours: Vec<(i32, i32)> = vec![
                    (i - 1, j - 1),
                    (i - 1, j),
                    (i - 1, j + 1),
                    (i, j - 1),
                    (i, j + 1),
                    (i + 1, j - 1),
                    (i + 1, j),
                    (i + 1, j + 1),
                ];
                for (k, (r, c)) in neighbours.into_iter().enumerate() {
                    if 0 <= r && r < m && 0 <= c && c < n && board[r as usize][c as usize] & 1 == 1
                    {
                        board[i as usize][j as usize] |= 1 << (k + 1);
                    }
                }
            }
        }
        for i in 0..m as usize {
            for j in 0..n as usize {
                let ele = board[i][j];
                let cnt = (ele >> 1).count_ones();
                if ele & 1 == 1 {
                    board[i][j] = if cnt < 2 || cnt > 3 { 0 } else { 1 };
                } else {
                    board[i][j] = if cnt == 3 { 1 } else { 0 };
                }
            }
        }
    }
}
