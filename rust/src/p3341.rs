use std::cmp::Reverse;
use std::collections::BinaryHeap;

struct Solution;

impl Solution {
    pub fn min_time_to_reach(move_time: Vec<Vec<i32>>) -> i32 {
        let n = move_time.len();
        let m = move_time[0].len();
        let mut dist = vec![vec![i64::MAX; m]; n];
        dist[0][0] = 0;
        let mut heap = BinaryHeap::new();
        heap.push(Reverse((0, 0, 0)));
        let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        while let Some(Reverse((time, x, y))) = heap.pop() {
            if x == n - 1 && y == m - 1 {
                return time as i32;
            }
            if time > dist[x][y] {
                continue;
            }
            for &(dx, dy) in &dirs {
                let nx = x as i32 + dx;
                let ny = y as i32 + dy;
                if nx >= 0 && nx < n as i32 && ny >= 0 && ny < m as i32 {
                    let nx = nx as usize;
                    let ny = ny as usize;
                    let s = std::cmp::max(time, move_time[nx][ny] as i64);
                    let new_time = s + 1;
                    if new_time < dist[nx][ny] {
                        dist[nx][ny] = new_time;
                        heap.push(Reverse((new_time, nx, ny)));
                    }
                }
            }
        }
        -1
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_min_time_to_reach() {
        assert_eq!(Solution::min_time_to_reach(vec![vec![0, 4], vec![4, 4]]), 6);
        assert_eq!(
            Solution::min_time_to_reach(vec![vec![0, 0, 0], vec![0, 0, 0]]),
            3
        );
    }
}
