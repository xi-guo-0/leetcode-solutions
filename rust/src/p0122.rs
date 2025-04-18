impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut profit = 0;
        for trend in prices.windows(2) {
            if trend[1] > trend[0] {
                profit += trend[1] - trend[0];
            }
        }
        profit
    }
}
