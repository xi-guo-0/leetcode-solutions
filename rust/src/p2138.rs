impl Solution {
    pub fn divide_string(s: String, k: i32, fill: char) -> Vec<String> {
        s.as_bytes()
            .chunks(k as usize)
            .map(|x| String::from_utf8(x.to_vec()).unwrap())
            .map(|mut x| {
                while x.len() < k as usize {
                    x.push(fill);
                }
                x
            })
            .collect::<Vec<String>>()
    }
}
