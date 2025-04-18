impl Solution {
    pub fn find_peaks(mountain: Vec<i32>) -> Vec<i32> {
        let m = mountain;
        let mut ans = Vec::<i32>::new();
        for i in 1..(m.len() - 1) {
            if m[i - 1] < m[i] && m[i] > m[i + 1] {
                ans.push(i as i32);
            }
        }
        ans
    }
}
