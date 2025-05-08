use std::cmp::Reverse;
use std::collections::BinaryHeap;

struct Solution;

impl Solution {
    pub fn min_time_to_reach(move_time: Vec<Vec<i32>>) -> i32 {
        let n = move_time.len();
        let m = move_time[0].len();
        let mut dist = vec![vec![[i32::MAX; 2]; m]; n];
        let mut heap = BinaryHeap::new();
        dist[0][0][0] = 0;
        heap.push(Reverse((0, 0, 0, 0)));
        let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        while let Some(Reverse((t, i, j, p))) = heap.pop() {
            if i == n - 1 && j == m - 1 {
                return t;
            }
            if t > dist[i][j][p] {
                continue;
            }
            for &(dx, dy) in &dirs {
                let ni = i as i32 + dx;
                let nj = j as i32 + dy;
                if ni >= 0 && nj >= 0 && ni < n as i32 && nj < m as i32 {
                    let x = ni as usize;
                    let y = nj as usize;
                    let s = t.max(move_time[x][y] as i32);
                    let step_time = if p == 0 { 1 } else { 2 };
                    let new_t = s + step_time;
                    let new_p = 1 - p;
                    if new_t < dist[x][y][new_p] {
                        dist[x][y][new_p] = new_t;
                        heap.push(Reverse((new_t, x, y, new_p)));
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
        assert_eq!(Solution::min_time_to_reach(vec![vec![0, 4], vec![4, 4]]), 7);
        assert_eq!(
            Solution::min_time_to_reach(vec![vec![0, 0, 0, 0], vec![0, 0, 0, 0]]),
            6
        );
        assert_eq!(Solution::min_time_to_reach(vec![vec![0, 1], vec![1, 2]]), 4);
    }
}
