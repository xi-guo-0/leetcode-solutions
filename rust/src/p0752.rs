use std::collections::HashSet;
use std::collections::VecDeque;

type State = [u8; 4];

struct Solution;

impl Solution {
    pub fn open_lock(deadends: Vec<String>, target: String) -> i32 {
        Self::open_lock_helper(
            deadends.into_iter().map(|s| Self::convert(s)).collect(),
            Self::convert(target),
        )
    }

    fn open_lock_helper(deadends: HashSet<State>, target: State) -> i32 {
        let init_state = [0; 4];
        let mut visited = HashSet::<State>::new();
        let mut q = VecDeque::<State>::new();
        let mut steps = 0;
        if deadends.contains(&init_state) {
            return -1;
        }
        visited.insert(init_state);
        q.push_back(init_state);
        while !q.is_empty() {
            let n = q.len();
            for _ in 0..n {
                let cur = q.pop_front().unwrap();
                if cur == target {
                    return steps;
                }
                for j in 0..4 {
                    let mut l = cur.clone();
                    let mut r = cur.clone();
                    l[j] = (l[j] + 1) % 10;
                    r[j] = (r[j] + 9) % 10;
                    if !deadends.contains(&l) && !visited.contains(&l) {
                        q.push_back(l);
                        visited.insert(l);
                    }
                    if !deadends.contains(&r) && !visited.contains(&r) {
                        q.push_back(r);
                        visited.insert(r);
                    }
                }
            }
            steps += 1;
        }
        -1
    }

    fn convert(s: String) -> State {
        s.chars()
            .take(4)
            .map(|c| c.to_digit(10).unwrap() as u8)
            .collect::<Vec<u8>>()
            .try_into()
            .unwrap()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_two_sum() {
        assert_eq!(
            Solution::open_lock(
                ["0201", "0101", "0102", "1212", "2002"]
                    .into_iter()
                    .map(String::from)
                    .collect(),
                String::from("0202")
            ),
            6
        );
        assert_eq!(
            Solution::open_lock(
                ["8888"].into_iter().map(String::from).collect(),
                String::from("0009")
            ),
            1
        );
        assert_eq!(
            Solution::open_lock(
                [
                    "8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"
                ]
                .into_iter()
                .map(String::from)
                .collect(),
                String::from("8888")
            ),
            -1
        );
    }
}
