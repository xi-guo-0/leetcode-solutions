impl Solution {
    pub fn min_remove_to_make_valid(s: String) -> String {
        let mut l = Vec::<usize>::new(); // Stack of unmatched left bracket indices
        let mut ans = Vec::<char>::new();
        for c in s.chars() {
            if c == '(' {
                l.push(ans.len());
                ans.push('(');
            } else if c == ')' {
                if let Some(p) = l.pop() {
                    ans.push(')');
                }
            } else {
                ans.push(c);
            }
        }
        for &x in &l {
            ans[x] = ' ';
        }
        ans.iter().filter(|&&c| c != ' ').collect()
    }
}
