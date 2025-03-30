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
    pub fn partition(head: Option<Box<ListNode>>, x: i32) -> Option<Box<ListNode>> {
        let mut less_than_x_head = Some(Box::new(ListNode::new(0)));
        let mut greater_or_equal_to_x_head = Some(Box::new(ListNode::new(0)));
        let mut less_than_x_tail = &mut less_than_x_head;
        let mut greater_or_equal_to_x_tail = &mut greater_or_equal_to_x_head;
        let mut current = head;
        while let Some(mut node) = current.take() {
            current = node.next.take();
            if node.val < x {
                less_than_x_tail.as_mut().unwrap().next = Some(node);
                less_than_x_tail = &mut less_than_x_tail.as_mut().unwrap().next;
            } else {
                greater_or_equal_to_x_tail.as_mut().unwrap().next = Some(node);
                greater_or_equal_to_x_tail = &mut greater_or_equal_to_x_tail.as_mut().unwrap().next;
            }
        }
        less_than_x_tail.as_mut().unwrap().next = greater_or_equal_to_x_head.unwrap().next;
        less_than_x_head.unwrap().next
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_partition() {
        assert_eq!(
            Solution::partition(ListNode::from_vec(vec![1, 4, 3, 2, 5, 2]), 3),
            ListNode::from_vec(vec![1, 2, 2, 4, 3, 5])
        );
        assert_eq!(
            Solution::partition(ListNode::from_vec(vec![2, 1]), 2),
            ListNode::from_vec(vec![1, 2])
        );
    }
}
