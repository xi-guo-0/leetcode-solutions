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
    pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() || head.as_ref().unwrap().next.is_none() {
            head
        } else if head.as_ref().unwrap().val == head.as_ref().unwrap().next.as_ref().unwrap().val {
            let v = head.as_ref().unwrap().val;
            let mut p = head.as_ref();
            while p.is_some() && p.unwrap().val == v {
                p = p.unwrap().next.as_ref();
            }
            if p.is_some() {
                Self::delete_duplicates(Some(p.unwrap().to_owned()))
            } else {
                None
            }
        } else {
            let t = head.unwrap();
            Some(Box::new(ListNode {
                val: t.val,
                next: Self::delete_duplicates(t.next),
            }))
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_delete_duplicates() {
        assert_eq!(
            Solution::delete_duplicates(ListNode::from_vec(vec![1, 2, 3, 3, 4, 4, 5])),
            ListNode::from_vec(vec![1, 2, 5])
        );
        assert_eq!(
            Solution::delete_duplicates(ListNode::from_vec(vec![1, 1, 1, 2, 3])),
            ListNode::from_vec(vec![2, 3])
        );
    }
}
