impl Solution {
    pub fn split_words_by_separator(words: Vec<String>, separator: char) -> Vec<String> {
        words
            .into_iter()
            .flat_map(|s| {
                s.split(separator)
                    .map(|x| x.to_owned())
                    .filter(|x| !x.is_empty())
                    .collect::<Vec<String>>()
            })
            .collect()
    }
}
