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
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        lists
            .into_iter()
            .fold(None, |acc, list| Self::merge_two_lists(acc, list))
    }

    pub fn merge_two_lists(
        list1: Option<Box<ListNode>>,
        list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        match (list1, list2) {
            (None, None) => None,
            (None, Some(l2)) => Some(l2),
            (Some(l1), None) => Some(l1),
            (Some(l1), Some(l2)) => {
                if l1.val <= l2.val {
                    Some(Box::new(ListNode {
                        val: l1.val,
                        next: Self::merge_two_lists(l1.next, Some(l2)),
                    }))
                } else {
                    Some(Box::new(ListNode {
                        val: l2.val,
                        next: Self::merge_two_lists(Some(l1), l2.next),
                    }))
                }
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_merge_k_lists() {
        assert_eq!(
            Solution::merge_k_lists(
                vec![vec![1, 4, 5], vec![1, 3, 4], vec![2, 6]]
                    .into_iter()
                    .map(ListNode::from_vec)
                    .collect::<Vec<Option<Box<ListNode>>>>()
            ),
            ListNode::from_vec(vec![1, 1, 2, 3, 4, 4, 5, 6])
        );
        assert_eq!(Solution::merge_k_lists(vec![]), ListNode::from_vec(vec![]));
        assert_eq!(
            Solution::merge_k_lists(vec![ListNode::from_vec(vec![])]),
            ListNode::from_vec(vec![])
        );
    }
}
