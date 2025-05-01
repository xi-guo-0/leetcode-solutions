use std::collections::VecDeque;

struct Solution;

impl Solution {
    pub fn max_task_assign(tasks: Vec<i32>, workers: Vec<i32>, pills: i32, strength: i32) -> i32 {
        let mut tasks = tasks;
        let mut workers = workers;
        tasks.sort();
        workers.sort_by(|a, b| b.cmp(a));
        let (mut left, mut right) = (0, tasks.len().min(workers.len()));
        let mut answer = 0;
        while left <= right {
            let mid = left + (right - left) / 2;
            if Self::can_assign(&tasks, &workers, mid, pills, strength) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        answer as i32
    }

    fn can_assign(tasks: &[i32], workers: &[i32], k: usize, pills: i32, strength: i32) -> bool {
        if k == 0 {
            return true;
        }
        let k = k as usize;
        let mut pills_remaining = pills;
        let mut deque = VecDeque::new();
        let mut worker_ptr = 0;
        for i in (0..k).rev() {
            let task = tasks[i];
            while worker_ptr < k && workers[worker_ptr] + strength >= task {
                deque.push_back(workers[worker_ptr]);
                worker_ptr += 1;
            }
            if let Some(&worker) = deque.front() {
                if worker >= task {
                    deque.pop_front();
                    continue;
                }
            }
            if pills_remaining > 0 {
                pills_remaining -= 1;
                if let Some(&worker) = deque.back() {
                    if worker + strength >= task {
                        deque.pop_back();
                        continue;
                    }
                }
            }
            return false;
        }
        true
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_max_task_assign() {
        assert_eq!(
            Solution::max_task_assign(vec![3, 2, 1], vec![0, 3, 3], 1, 1),
            3
        );
        assert_eq!(
            Solution::max_task_assign(vec![5, 4], vec![0, 0, 0], 1, 5),
            1
        );
        assert_eq!(
            Solution::max_task_assign(vec![10, 15, 30], vec![0, 10, 10, 10, 10], 3, 10),
            2
        );
    }
}
