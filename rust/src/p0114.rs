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
    pub fn flatten(root: &mut Option<Rc<RefCell<TreeNode>>>) {
        Self::helper(root);
    }
    fn helper(node: &Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        match node {
            None => None,
            Some(node) => {
                let left_tail = Self::helper(&node.borrow().left);
                let right_tail = Self::helper(&node.borrow().right);

                if let Some(ref left_tail) = left_tail {
                    let right_tmp = node.borrow_mut().right.take();
                    left_tail.borrow_mut().right = right_tmp;
                    let left_tmp = node.borrow_mut().left.take();
                    node.borrow_mut().right = left_tmp;
                }

                [right_tail, left_tail, Some(node.clone())]
                    .into_iter()
                    .find(Option::is_some)
                    .unwrap()
            }
        }
    }
}
