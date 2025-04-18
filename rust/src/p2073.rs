impl Solution {
    pub fn time_required_to_buy(tickets: Vec<i32>, k: i32) -> i32 {
        let loops = tickets[k as usize];
        let mut ans = 0;
        for i in 0..(k + 1) {
            ans += std::cmp::min(tickets[i as usize], loops);
        }
        for i in (k as usize + 1)..tickets.len() {
            ans += std::cmp::min(tickets[i as usize], loops - 1);
        }

        ans
    }
}
