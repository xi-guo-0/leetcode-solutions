impl Solution {
    pub fn make_equal(words: Vec<String>) -> bool {
        let n = words.len();
        let mut oc = [0; 128];
        for word in words.into_iter() {
            for c in word.chars() {
                oc[c as usize] += 1;
            }
        }
        oc.into_iter().all(|x| x % n == 0)
    }
}
