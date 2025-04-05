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
    pub fn rotate_right(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        let len = Self::list_length(&head);
        if len <= 1 {
            return head;
        }
        let k = (len - (k as usize) % len) % len;
        if k == 0 {
            head
        } else {
            let (head, tail) = Self::split_at(head, k - 1);
            Self::append(tail, head)
        }
    }

    fn split_at(
        mut head: Option<Box<ListNode>>,
        index: usize,
    ) -> (Option<Box<ListNode>>, Option<Box<ListNode>>) {
        let mut count = 0;
        let mut current = &mut head;
        while let Some(node) = current {
            if count == index {
                let rest = node.next.take();
                return (head, rest);
            }
            count += 1;
            current = &mut node.next;
        }
        (head, None)
    }

    fn list_length(list: &Option<Box<ListNode>>) -> usize {
        let mut current = list;
        let mut length = 0;
        while let Some(node) = current {
            length += 1;
            current = &node.next;
        }
        length
    }

    fn append(
        mut first_list: Option<Box<ListNode>>,
        second_list: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut current = &mut first_list;
        while let Some(node) = current {
            if node.next.is_none() {
                node.next = second_list;
                break;
            }
            current = &mut node.next;
        }
        first_list
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_rotate_right() {
        assert_eq!(
            Solution::rotate_right(ListNode::from_vec(vec![1, 2, 3, 4, 5]), 2),
            ListNode::from_vec(vec![4, 5, 1, 2, 3])
        );
        assert_eq!(
            Solution::rotate_right(ListNode::from_vec(vec![0, 1, 2]), 4),
            ListNode::from_vec(vec![2, 0, 1])
        );
    }
}
