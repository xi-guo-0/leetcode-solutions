struct Solution;

impl Solution {
    pub fn num_tilings(n: i32) -> i32 {
        let mut a: u64 = 1;
        let mut b: u64 = 2;
        let mut c: u64 = 5;
        let mut t: u64 = 14;
        let m: u64 = 1_000_000_007;

        for i in 1..n {
            t = (a + 2 * c) % m;
            a = b;
            b = c;
            c = t;
        }

        a as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_num_tilings() {
        assert_eq!(Solution::num_tilings(3), 5);
        assert_eq!(Solution::num_tilings(1), 1);
    }
}
