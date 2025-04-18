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
    pub fn kth_smallest(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> i32 {
        fn count_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
            if let Some(node) = root {
                1 + count_nodes(node.borrow().left.clone())
                    + count_nodes(node.borrow().right.clone())
            } else {
                0
            }
        }
        let l = count_nodes(root.clone().unwrap().borrow().left.clone());
        if k < l + 1 {
            Solution::kth_smallest(root.unwrap().borrow().left.clone(), k)
        } else if k == l + 1 {
            root.unwrap().borrow().val
        } else {
            Solution::kth_smallest(root.unwrap().borrow().right.clone(), k - l - 1)
        }
    }
}
