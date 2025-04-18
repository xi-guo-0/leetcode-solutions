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
    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        root.is_none()
            || Self::helper(
                root.clone().unwrap().borrow().left.clone(),
                root.clone().unwrap().borrow().right.clone(),
            )
    }

    fn helper(n0: Option<Rc<RefCell<TreeNode>>>, n1: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match (n0, n1) {
            (None, None) => true,
            (Some(a), Some(b)) => {
                a.borrow().val == b.borrow().val
                    && Self::helper(a.borrow().left.clone(), b.borrow().right.clone())
                    && Self::helper(a.borrow().right.clone(), b.borrow().left.clone())
            }
            _ => false,
        }
    }
}
