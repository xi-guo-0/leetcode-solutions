// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

impl Solution {
    pub fn right_side_view(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut ans = vec![];
        let mut cur = VecDeque::new();
        let mut next = VecDeque::new();
        if root.is_some() {
            cur.push_back(root);
        }
        while !cur.is_empty() {
            let mut rightmost = None;
            while !cur.is_empty() {
                rightmost = cur.pop_front().unwrap();
                if rightmost.clone().unwrap().borrow().left.is_some() {
                    next.push_back(rightmost.clone().unwrap().borrow().left.clone());
                }
                if rightmost.clone().unwrap().borrow().right.is_some() {
                    next.push_back(rightmost.clone().unwrap().borrow().right.clone());
                }
            }
            ans.push(rightmost.unwrap().borrow().val);
            std::mem::swap(&mut cur, &mut next);
        }
        ans
    }
}
