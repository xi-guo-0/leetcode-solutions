impl Solution {
    pub fn maximum_odd_binary_number(s: String) -> String {
        let mut ans = String::new();
        let ones = s.chars().filter(|&x| x == '1').count();
        for i in 0..(ones - 1) {
            ans.push('1');
        }
        for i in 0..(s.len() - ones) {
            ans.push('0');
        }
        ans.push('1');
        ans
    }
}
