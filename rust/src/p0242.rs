impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut freq = [0; 26];

        s.as_bytes().iter().for_each(|c| {
            freq[(c - b'a') as usize] += 1;
        });
        t.as_bytes().iter().for_each(|c| {
            freq[(c - b'a') as usize] -= 1;
        });

        freq.into_iter().all(|count| count == 0)
    }
}
