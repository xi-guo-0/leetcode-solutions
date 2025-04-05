use std::cell::RefCell;
use std::rc::Rc;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

struct Solution;

impl Solution {
    pub fn add_one_row(
        root: Option<Rc<RefCell<TreeNode>>>,
        val: i32,
        depth: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_none() {
            None
        } else if depth == 1 {
            Some(Rc::new(RefCell::new(TreeNode {
                val,
                left: root,
                right: None,
            })))
        } else if depth == 2 {
            let mut node = root.as_ref().unwrap().borrow_mut();
            node.left = Some(Rc::new(RefCell::new(TreeNode {
                val,
                left: node.left.clone(),
                right: None,
            })));
            node.right = Some(Rc::new(RefCell::new(TreeNode {
                val,
                left: None,
                right: node.right.clone(),
            })));
            root.clone()
        } else {
            let ret = root.as_ref().unwrap();
            let node = ret.borrow_mut();
            Self::add_one_row(node.left.clone(), val, depth - 1);
            Self::add_one_row(node.right.clone(), val, depth - 1);
            root.clone()
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_add_one_row() {}
}
