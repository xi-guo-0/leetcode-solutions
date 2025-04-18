impl Solution {
    pub fn make_smallest_palindrome(s: String) -> String {
        let mut vc: Vec<char> = s.chars().collect();
        for i in 0..(vc.len() / 2) {
            let il = i as usize;
            let ir = vc.len() - il - 1;
            let t = std::cmp::min(vc[il], vc[ir]);
            vc[il] = t;
            vc[ir] = t;
        }
        vc.iter().collect()
    }
}
