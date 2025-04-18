impl Solution {
    pub fn count_triples(n: i32) -> i32 {
        let mut ans = 0;
        for a in 1..=n {
            for b in 1..=n {
                for c in 1..=n {
                    if a * a + b * b == c * c {
                        ans += 1
                    }
                }
            }
        }
        ans
    }
}
