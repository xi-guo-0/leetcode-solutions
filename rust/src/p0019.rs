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
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut r = Box::new(ListNode { val: 0, next: head });
        let mut b = r.clone();
        let mut a = r.as_mut();
        let mut i = 0;
        while b.next.is_some() {
            i += 1;
            if i > n {
                a = a.next.as_mut().unwrap();
            }
            b = b.next.unwrap();
        }
        let n = a.next.as_mut().unwrap();
        a.next = n.next.clone();
        r.next
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_remove_nth_from_end() {
        assert_eq!(
            Solution::remove_nth_from_end(ListNode::from_vec(vec![1, 2, 3, 4, 5]), 2),
            ListNode::from_vec(vec![1, 2, 3, 5])
        );
        assert_eq!(
            Solution::remove_nth_from_end(ListNode::from_vec(vec![1]), 1),
            ListNode::from_vec(vec![])
        );
        assert_eq!(
            Solution::remove_nth_from_end(ListNode::from_vec(vec![1, 2]), 1),
            ListNode::from_vec(vec![1])
        );
    }
}
