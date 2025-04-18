// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn remove_nodes(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.as_ref().unwrap().next.is_some() {
            let val = head.as_ref().unwrap().val;
            let next = Self::remove_nodes(head.unwrap().next);
            if val < next.as_ref().unwrap().val {
                next
            } else {
                Some(Box::new(ListNode { val, next }))
            }
        } else {
            head
        }
    }
}
