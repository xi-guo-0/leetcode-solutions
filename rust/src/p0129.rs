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
    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn helper(root: Option<Rc<RefCell<TreeNode>>>, path_total: i32) -> i32 {
            if let Some(node) = root {
                let node = node.borrow();
                if node.left.is_none() && node.right.is_none() {
                    path_total + node.val
                } else {
                    let t = (path_total + node.val) * 10;
                    helper(node.left.clone(), t) + helper(node.right.clone(), t)
                }
            } else {
                0
            }
        }
        helper(root, 0)
    }
}
