struct Solution;

impl Solution {
    pub fn island_perimeter(grid: Vec<Vec<i32>>) -> i32 {
        let mut perimeter = 0;
        for i in 0..grid.len() {
            for j in 0..grid[0].len() {
                if grid[i][j] == 1 {
                    if 0 == i || 0 == grid[i - 1][j] {
                        perimeter += 1;
                    }
                    if 0 == j || 0 == grid[i][j - 1] {
                        perimeter += 1;
                    }
                    if grid.len() - 1 <= i || 0 == grid[i + 1][j] {
                        perimeter += 1;
                    }
                    if grid[i].len() - 1 <= j || 0 == grid[i][j + 1] {
                        perimeter += 1;
                    }
                }
            }
        }
        perimeter
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_island_perimeter() {
        let grid = vec![
            vec![0, 1, 0, 0],
            vec![1, 1, 1, 0],
            vec![0, 1, 0, 0],
            vec![1, 1, 0, 0],
        ];
        assert_eq!(Solution::island_perimeter(grid), 16);

        let grid = vec![vec![1]];
        assert_eq!(Solution::island_perimeter(grid), 4);

        let grid = vec![vec![1, 0]];
        assert_eq!(Solution::island_perimeter(grid), 4);
    }
}
