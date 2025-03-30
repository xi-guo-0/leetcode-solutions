use std::collections::BinaryHeap;

struct Solution;

impl Solution {
    pub fn mincost_to_hire_workers(quality: Vec<i32>, wage: Vec<i32>, k: i32) -> f64 {
        let k = k as usize;
        if k == 1 {
            return *wage.iter().min().unwrap() as f64;
        }
        let n = quality.len();
        let mut ids: Vec<_> = (0..n).collect();
        ids.sort_unstable_by(|&a, &b| (wage[a] * quality[b]).cmp(&(wage[b] * quality[a])));

        let mut res = std::f64::MAX;
        let mut heap = BinaryHeap::new();
        let mut sum = 0;
        for i in 0..k - 1 {
            heap.push(quality[ids[i]]);
            sum += quality[ids[i]];
        }
        for i in k - 1..n {
            let i = ids[i];
            let scale = wage[i] as f64 / quality[i] as f64;
            let tmp = (sum + quality[i]) as f64 * scale;
            if tmp < res {
                res = tmp;
            }
            if quality[i] < *heap.peek().unwrap() {
                sum -= *heap.peek().unwrap();
                heap.pop();
                sum += quality[i];
                heap.push(quality[i]);
            }
        }
        res
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_mincost_to_hire_workers() {
        assert_eq!(
            Solution::mincost_to_hire_workers(vec![10, 20, 5], vec![70, 50, 30], 2),
            105.00000
        );
        assert_eq!(
            Solution::mincost_to_hire_workers(vec![3, 1, 10, 10, 1], vec![4, 8, 2, 2, 7], 3),
            30.666666666666664
        );
    }
}
