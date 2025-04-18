impl Solution {
    pub fn count_tested_devices(battery_percentages: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut last = 0;
        for x in battery_percentages.iter() {
            if (last < *x) {
                ans += 1;
                last += 1;
            }
        }
        ans
    }
}
