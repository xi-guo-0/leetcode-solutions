use std::collections::BinaryHeap;

impl Solution {
    pub fn pick_gifts(gifts: Vec<i32>, k: i32) -> i64 {
        let mut k = k;
        let mut pq = BinaryHeap::from(gifts);

        while let Some(v) = pq.pop() {
            let x = f64::sqrt(v as f64 + 0.5) as i32;
            pq.push(x);
            k -= 1;
            if k == 0 {
                break;
            }
        }

        pq.into_iter().map(|a| a as i64).sum::<i64>()
    }
}
