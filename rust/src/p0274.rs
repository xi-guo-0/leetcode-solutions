impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let n = citations.len();
        let mut ans = 0;

        let mut citations_sorted = citations.clone();
        citations_sorted.sort();

        for i in 0..n {
            ans = ans.max(citations_sorted[i].min((n - i) as i32));
        }

        ans
    }
}
