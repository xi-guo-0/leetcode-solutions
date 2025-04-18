impl Solution {
    pub fn is_happy(mut n: i32) -> bool {
        use std::collections::HashSet;
        let mut set = HashSet::<i32>::new();
        while n != 1 && !set.contains(&n) {
            set.insert(n);
            let mut s = 0;
            while n != 0 {
                s += (n % 10) * (n % 10);
                n /= 10;
            }
            n = s;
        }
        n == 1
    }
}
