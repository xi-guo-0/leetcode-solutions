use std::cell::RefCell;
use std::rc::Rc;

// Definition for a binary tree node.
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
    pub fn lca_deepest_leaves(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        fn helper(node: &Option<Rc<RefCell<TreeNode>>>) -> (i32, Option<Rc<RefCell<TreeNode>>>) {
            match node {
                None => (0, None),
                Some(n) => {
                    let n_ref = n.borrow();
                    let (left_depth, left_lca) = helper(&n_ref.left);
                    let (right_depth, right_lca) = helper(&n_ref.right);
                    match left_depth.cmp(&right_depth) {
                        std::cmp::Ordering::Greater => (left_depth + 1, left_lca),
                        std::cmp::Ordering::Less => (right_depth + 1, right_lca),
                        std::cmp::Ordering::Equal => (left_depth + 1, Some(n.clone())),
                    }
                }
            }
        }
        helper(&root).1
    }

    pub fn vec_to_tree(vec: &[Option<i32>], index: usize) -> Option<Rc<RefCell<TreeNode>>> {
        if index >= vec.len() || vec[index].is_none() {
            return None;
        }

        let mut node = TreeNode::new(vec[index].unwrap());
        node.left = Self::vec_to_tree(vec, 2 * index + 1);
        node.right = Self::vec_to_tree(vec, 2 * index + 2);

        Some(Rc::new(RefCell::new(node)))
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_lca_deepest_leaves() {
        let tree1 = Solution::vec_to_tree(
            &[
                Some(3),
                Some(5),
                Some(1),
                Some(6),
                Some(2),
                Some(0),
                Some(8),
                None,
                None,
                Some(7),
                Some(4),
            ],
            0,
        );
        let expected1 = Solution::vec_to_tree(&[Some(2), Some(7), Some(4)], 0);
        assert_eq!(Solution::lca_deepest_leaves(tree1), expected1);

        let tree2 = Solution::vec_to_tree(&[Some(1)], 0);
        let expected2 = Solution::vec_to_tree(&[Some(1)], 0);
        assert_eq!(Solution::lca_deepest_leaves(tree2), expected2);

        let tree3 = Solution::vec_to_tree(&[Some(0), Some(1), Some(3), None, Some(2)], 0);
        let expected3 = Solution::vec_to_tree(&[Some(2)], 0);
        assert_eq!(Solution::lca_deepest_leaves(tree3), expected3);
    }
}
