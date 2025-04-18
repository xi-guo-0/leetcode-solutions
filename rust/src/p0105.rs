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
    pub fn build_tree(preorder: Vec<i32>, inorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::helper(&preorder, &inorder)
    }

    fn helper(preorder: &[i32], inorder: &[i32]) -> Option<Rc<RefCell<TreeNode>>> {
        if preorder.is_empty() || inorder.is_empty() {
            None
        } else {
            let val = preorder[0];
            let index = inorder.iter().position(|&x| x == val).unwrap();
            Some(Rc::new(RefCell::new(TreeNode {
                val,
                left: Self::helper(&preorder[1..index + 1], &inorder[0..index]),
                right: Self::helper(
                    &preorder[index + 1..preorder.len()],
                    &inorder[index + 1..inorder.len()],
                ),
            })))
        }
    }
}
