struct Solution;

impl Solution {
    pub fn full_justify(words: Vec<String>, max_width: i32) -> Vec<String> {
        let max_width = max_width as usize;
        let page = Self::split_lines(words, max_width);
        let lines_count = page.len();
        let normal_lines = &page[0..lines_count - 1];
        let last_line = &page[lines_count - 1];
        let mut ans = normal_lines
            .into_iter()
            .map(|ws| Self::join_line(ws, max_width))
            .collect::<Vec<String>>();
        ans.push(Self::process_last_line(last_line, max_width));
        ans
    }

    fn split_lines(words: Vec<String>, max_width: usize) -> Vec<Vec<String>> {
        let mut page: Vec<Vec<String>> = Vec::new();
        for word in words.into_iter() {
            if page.is_empty()
                || page
                    .last()
                    .unwrap()
                    .iter()
                    .map(|s| s.len() + 1)
                    .sum::<usize>()
                    + word.len()
                    > max_width
            {
                page.push(vec![]);
            }
            let n = page.len() - 1;
            page[n].push(word);
        }
        page
    }

    fn join_line(words: &Vec<String>, max_width: usize) -> String {
        let mut ans = words[0].clone();
        let gap_count = std::cmp::max(1, words.len() - 1);
        let space_count = max_width - words.iter().map(|s| s.len()).sum::<usize>();
        for i in 1..words.len() {
            let cnt = space_count / gap_count
                + if i < space_count % gap_count + 1 {
                    1
                } else {
                    0
                };
            for _ in 0..cnt {
                ans.push(' ');
            }
            ans.push_str(&words[i]);
        }
        if words.len() == 1 {
            for _ in 0..space_count {
                ans.push(' ');
            }
        }
        ans
    }

    fn process_last_line(words: &Vec<String>, max_width: usize) -> String {
        let mut ans = words.join(" ");
        while ans.len() < max_width {
            ans.push(' ');
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_full_justify() {
        assert_eq!(
            Solution::full_justify(
                vec![
                    "This",
                    "is",
                    "an",
                    "example",
                    "of",
                    "text",
                    "justification."
                ]
                .into_iter()
                .map(String::from)
                .collect(),
                16
            ),
            vec!["This    is    an", "example  of text", "justification.  "]
        );
        assert_eq!(
            Solution::full_justify(
                vec!["What", "must", "be", "acknowledgment", "shall", "be"]
                    .into_iter()
                    .map(String::from)
                    .collect(),
                16
            ),
            vec!["What   must   be", "acknowledgment  ", "shall be        "]
        );
        assert_eq!(
            Solution::full_justify(
                vec![
                    "Science",
                    "is",
                    "what",
                    "we",
                    "understand",
                    "well",
                    "enough",
                    "to",
                    "explain",
                    "to",
                    "a",
                    "computer.",
                    "Art",
                    "is",
                    "everything",
                    "else",
                    "we",
                    "do"
                ]
                .into_iter()
                .map(String::from)
                .collect(),
                20
            ),
            vec![
                "Science  is  what we",
                "understand      well",
                "enough to explain to",
                "a  computer.  Art is",
                "everything  else  we",
                "do                  "
            ]
        );
    }
}
