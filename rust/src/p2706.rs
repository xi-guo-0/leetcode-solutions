impl Solution {
    pub fn buy_choco(mut prices: Vec<i32>, money: i32) -> i32 {
        prices.sort();
        let s = prices[0] + prices[1];
        if money >= s {
            money - s
        } else {
            money
        }
    }
}
