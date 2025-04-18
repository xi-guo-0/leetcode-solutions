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
use std::rc::Rc;
impl Solution {
    pub fn evaluate_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let root = root.unwrap();
        let t = root.borrow();
        let val = t.val;
        let left = t.left.clone();
        let right = t.right.clone();
        match val {
            3 => Self::evaluate_tree(left) && Self::evaluate_tree(right),
            2 => Self::evaluate_tree(left) || Self::evaluate_tree(right),
            1 => true,
            _ => false,
        }
    }
}
