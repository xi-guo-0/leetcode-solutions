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
    pub fn build_tree(inorder: Vec<i32>, postorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::helper(&inorder, &postorder)
    }

    fn helper(inorder: &[i32], postorder: &[i32]) -> Option<Rc<RefCell<TreeNode>>> {
        if inorder.is_empty() || postorder.is_empty() {
            None
        } else {
            let val = postorder[postorder.len() - 1];
            let index = inorder.iter().position(|&x| x == val).unwrap();
            Some(Rc::new(RefCell::new(TreeNode {
                val,
                left: Self::helper(&inorder[0..index], &postorder[0..index]),
                right: Self::helper(
                    &inorder[index + 1..inorder.len()],
                    &postorder[index..postorder.len() - 1],
                ),
            })))
        }
    }
}
