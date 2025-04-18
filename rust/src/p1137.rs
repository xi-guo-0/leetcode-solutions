impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        Self::helper(n, 0, 1, 1)
    }

    fn helper(n: i32, a: i32, b: i32, c: i32) -> i32 {
        match n {
            0 => a,
            1 => b,
            2 => c,
            _ => Self::helper(n - 1, b, c, a + b + c),
        }
    }
}
