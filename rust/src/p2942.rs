impl Solution {
    pub fn find_words_containing(words: Vec<String>, x: char) -> Vec<i32> {
        let mut ans = Vec::<i32>::new();
        for (i, word) in words.into_iter().enumerate() {
            if word.contains(x) {
                ans.push(i as i32);
            }
        }
        ans
    }
}
