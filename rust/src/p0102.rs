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
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = vec![];
        let mut cur = VecDeque::new();
        let mut next = VecDeque::new();
        if root.is_some() {
            cur.push_back(root);
        }
        while !cur.is_empty() {
            let mut row = vec![];
            while !cur.is_empty() {
                let node = cur.pop_front().unwrap();
                if node.clone().unwrap().borrow().left.is_some() {
                    next.push_back(node.clone().unwrap().borrow().left.clone());
                }
                if node.clone().unwrap().borrow().right.is_some() {
                    next.push_back(node.clone().unwrap().borrow().right.clone());
                }
                row.push(node.unwrap().borrow().val);
            }
            ans.push(row);
            std::mem::swap(&mut cur, &mut next);
        }
        ans
    }
}
