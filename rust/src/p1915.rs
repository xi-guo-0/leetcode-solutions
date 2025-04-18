impl Solution {
    pub fn wonderful_substrings(word: String) -> i64 {
        let mut cnt: [i64; 1024] = [0; 1024];
        let (mut total, mut prefix) = (0, 0);
        cnt[0] = 1;

        for c in word.bytes() {
            prefix ^= (1 << (c - 97)) as usize;
            total += cnt[prefix];
            for i in 0..10 {
                total += cnt[prefix ^ (1 << i)];
            }
            cnt[prefix] += 1;
        }
        return total;
    }
}
