impl Solution {
    pub fn find_champion(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len() - 1;
        grid.into_iter()
            .enumerate()
            .map(|(i, row)| {
                if row.iter().sum::<i32>() as usize == m {
                    i
                } else {
                    0
                }
            })
            .max()
            .unwrap() as i32
    }
}
