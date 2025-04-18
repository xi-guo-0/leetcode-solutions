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
    pub fn max_path_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn helper(root: Option<Rc<RefCell<TreeNode>>>) -> (i32, i32) {
            use std::cmp::max;
            if let Some(node) = root {
                let node = node.borrow();
                let val = node.val;
                let l = helper(node.left.clone());
                let r = helper(node.right.clone());
                let sum = val + max(0, l.1) + max(0, r.1);
                (max(l.0, max(r.0, sum)), val + max(0, max(l.1, r.1)))
            } else {
                (i32::MIN, 0)
            }
        }
        helper(root).0
    }
}
