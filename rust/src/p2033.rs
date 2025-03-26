struct Solution;

impl Solution {
    pub fn min_operations(grid: Vec<Vec<i32>>, x: i32) -> i32 {
        let r = grid[0][0] % x;
        let mut a: Vec<i32> = vec![];
        for row in grid.into_iter() {
            for j in row.into_iter() {
                if j % x != r {
                    return -1;
                } else {
                    a.push(j / x);
                }
            }
        }
        a.sort();
        let m = a[a.len() / 2];
        a.into_iter().map(|e| (e - m).abs()).sum()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_min_operations() {
        assert_eq!(Solution::min_operations(vec![vec![2, 4], vec![6, 8]], 2), 4);
        assert_eq!(Solution::min_operations(vec![vec![1, 5], vec![2, 3]], 1), 5);
        assert_eq!(
            Solution::min_operations(vec![vec![1, 2], vec![3, 4]], 2),
            -1
        );
    }
}
