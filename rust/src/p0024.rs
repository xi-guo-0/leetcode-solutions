#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }

    pub fn from_vec(vec: Vec<i32>) -> Option<Box<ListNode>> {
        let mut head = None;
        for &v in vec.iter().rev() {
            let mut node = ListNode::new(v);
            node.next = head;
            head = Some(Box::new(node));
        }
        head
    }
}

struct Solution;

impl Solution {
    pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        match head {
            Some(mut first) => match first.next {
                Some(mut second) => {
                    first.next = Solution::swap_pairs(second.next);
                    second.next = Some(first);
                    Some(second)
                }
                None => Some(first),
            },
            None => None,
        }
    }
}

#[cfg(test)]
mod tests {
    use std::str::FromStr;

    use super::*;

    #[test]
    fn test_swap_pairs() {
        assert_eq!(
            Solution::swap_pairs(ListNode::from_vec(vec![1, 2, 3, 4])),
            ListNode::from_vec(vec![2, 1, 4, 3])
        );
        assert_eq!(
            Solution::swap_pairs(ListNode::from_vec(vec![])),
            ListNode::from_vec(vec![])
        );
        assert_eq!(
            Solution::swap_pairs(ListNode::from_vec(vec![1])),
            ListNode::from_vec(vec![1])
        );
        assert_eq!(
            Solution::swap_pairs(ListNode::from_vec(vec![1, 2, 3])),
            ListNode::from_vec(vec![2, 1, 3])
        );
    }
}
