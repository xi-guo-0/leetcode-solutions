impl Solution {
    pub fn max_length_between_equal_characters(s: String) -> i32 {
        let mut oc = vec![vec![s.len() as i32, -1]; 128];
        for (i, c) in s.chars().enumerate() {
            let j = c as usize;
            oc[j][0] = std::cmp::min(oc[j][0], i as i32);
            oc[j][1] = std::cmp::max(oc[j][1], i as i32);
        }
        let mut ans = -1;
        for p in oc.into_iter() {
            ans = std::cmp::max(ans, p[1] - p[0] - 1);
        }
        ans
    }
}
