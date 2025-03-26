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
    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        fn helper(root: Option<Rc<RefCell<TreeNode>>>, lower: i64, upper: i64) -> bool {
            match root {
                None => true,
                Some(node) => {
                    let node = node.borrow();
                    let val = node.val as i64;
                    lower < val
                        && val < upper
                        && helper(node.left.clone(), lower, val)
                        && helper(node.right.clone(), val, upper)
                }
            }
        }
        helper(root, i64::MIN, i64::MAX)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn build_tree(vals: Vec<Option<i32>>) -> Option<Rc<RefCell<TreeNode>>> {
        if vals.is_empty() || vals[0].is_none() {
            return None;
        }

        let root = Rc::new(RefCell::new(TreeNode::new(vals[0].unwrap())));
        let mut queue = vec![root.clone()];
        let mut i = 1;

        while i < vals.len() {
            let current = queue.remove(0);
            let mut node = current.borrow_mut();

            if let Some(left_val) = vals[i] {
                let left_node = Rc::new(RefCell::new(TreeNode::new(left_val)));
                node.left = Some(left_node.clone());
                queue.push(left_node);
            }
            i += 1;

            if i < vals.len() {
                if let Some(right_val) = vals[i] {
                    let right_node = Rc::new(RefCell::new(TreeNode::new(right_val)));
                    node.right = Some(right_node.clone());
                    queue.push(right_node);
                }
                i += 1;
            }
        }

        Some(root)
    }

    #[test]
    fn test_is_valid_bst() {
        let root = build_tree(vec![Some(2), Some(1), Some(3)]);
        assert_eq!(Solution::is_valid_bst(root), true);

        let root = build_tree(vec![
            Some(5),
            Some(1),
            Some(4),
            None,
            None,
            Some(3),
            Some(6),
        ]);
        assert_eq!(Solution::is_valid_bst(root), false);
    }
}
