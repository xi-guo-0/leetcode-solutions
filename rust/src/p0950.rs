use std::collections::VecDeque;

struct Solution;

impl Solution {
    pub fn deck_revealed_increasing(deck: Vec<i32>) -> Vec<i32> {
        let mut deck = deck;
        deck.sort();
        let mut deque = VecDeque::<i32>::new();
        deck.iter().rev().for_each(|x| {
            deque.push_front(*x);
            let t = deque.pop_back().unwrap();
            deque.push_front(t);
        });
        let t = deque.pop_front().unwrap();
        deque.push_back(t);
        deque.into()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_deck_revealed_increasing() {
        assert_eq!(
            Solution::deck_revealed_increasing(vec![17, 13, 11, 2, 3, 5, 7]),
            vec![2, 13, 3, 11, 5, 17, 7]
        );
        assert_eq!(
            Solution::deck_revealed_increasing(vec![1, 1000]),
            vec![1, 1000]
        );
    }
}
