fn c(n: i32) -> i32 {
    if n < 2 {
        return 0;
    }
    n * (n - 1) / 2
}

impl Solution {
    pub fn distribute_candies(n: i32, l: i32) -> i32 {
        c(n + 2) - 3 * c(n - l + 1) + 3 * c(n - 2 * l) - c(n - 3 * l - 1)
    }
}
