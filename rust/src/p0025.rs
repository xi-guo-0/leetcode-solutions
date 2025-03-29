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
    pub fn reverse_k_group(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        if head.is_none() || head.as_ref().unwrap().next.is_none() || k < 2 {
            return head;
        }
        let mut next_group = head.as_ref();
        for _ in 0..k {
            if next_group.is_some() {
                next_group = next_group.unwrap().next.as_ref();
            } else {
                return head;
            }
        }
        let mut dummy = Box::new(ListNode {
            val: 0,
            next: if next_group.is_some() {
                Self::reverse_k_group(Some(next_group.unwrap().clone()), k)
            } else {
                None
            },
        });
        let mut cur = head.as_ref();
        while cur != next_group {
            let next = cur.unwrap().next.as_ref();
            let t = cur.unwrap();
            let dummy_next = dummy.next;
            dummy.next = Some(Box::new(ListNode {
                val: t.val,
                next: dummy_next,
            }));
            cur = next;
        }
        dummy.next
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_reverse_k_group() {
        assert_eq!(
            Solution::reverse_k_group(ListNode::from_vec(vec![1, 2, 3, 4, 5]), 2),
            ListNode::from_vec(vec![2, 1, 4, 3, 5])
        );
        assert_eq!(
            Solution::reverse_k_group(ListNode::from_vec(vec![1, 2, 3, 4, 5]), 3),
            ListNode::from_vec(vec![3, 2, 1, 4, 5])
        );
    }
}
