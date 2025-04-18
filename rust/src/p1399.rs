impl Solution {
    pub fn count_largest_group(n: i32) -> i32 {
        let mut h = [0; 37];
        let mut max = 1;
        for i in 1..=n {
            let mut j = i;
            let mut c = 0;
            while j > 0 {
                c += j % 10;
                j /= 10;
            }
            h[c as usize] += 1;
            max = std::cmp::max(max, h[c as usize]);
        }
        h.into_iter().filter(|x| *x == max).count() as i32
    }
}
