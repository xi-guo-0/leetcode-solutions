use std::cmp::max;
use std::cmp::min;
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut profit: i32 = 0;
        let mut lowest = prices[0];
        for i in 1..prices.len() {
            lowest = min(lowest, prices[i - 1]);
            profit = max(profit, prices[i] - lowest);
        }
        profit
    }
}
