impl Solution {
    pub fn maximum_happiness_sum(mut arr: Vec<i32>, k: i32) -> i64 {
        arr.sort_unstable();
        let mut res = 0;
        for i in (0..k as usize).rev() {
            res += 0.max(arr[arr.len() - i - 1] - i as i32) as i64;
        }
        return res;
    }
}
