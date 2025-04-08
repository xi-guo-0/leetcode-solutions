use crate::tree;
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
    pub fn sum_of_left_leaves(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::sum_of_left_leaves_helper(root, false)
    }

    fn sum_of_left_leaves_helper(root: Option<Rc<RefCell<TreeNode>>>, is_left: bool) -> i32 {
        if let Some(node) = root {
            let node = node.borrow();
            if node.left.is_none() && node.right.is_none() && is_left {
                node.val
            } else {
                Self::sum_of_left_leaves_helper(node.left.clone(), true)
                    + Self::sum_of_left_leaves_helper(node.right.clone(), false)
            }
        } else {
            0
        }
    }
}

fn leetcode_input_to_tree(input: &[Option<i32>]) -> Option<Rc<RefCell<TreeNode>>> {
    if input.is_empty() || input[0].is_none() {
        return None;
    }
    let root = Rc::new(RefCell::new(TreeNode::new(input[0].unwrap())));
    let mut queue = std::collections::VecDeque::new();
    queue.push_back(Rc::clone(&root));
    let mut index = 1;
    while !queue.is_empty() && index < input.len() {
        let node = queue.pop_front().unwrap();
        let mut node = node.borrow_mut();
        if index < input.len() {
            if let Some(val) = input[index] {
                let left = Rc::new(RefCell::new(TreeNode::new(val)));
                node.left = Some(Rc::clone(&left));
                queue.push_back(left);
            }
            index += 1;
        }
        if index < input.len() {
            if let Some(val) = input[index] {
                let right = Rc::new(RefCell::new(TreeNode::new(val)));
                node.right = Some(Rc::clone(&right));
                queue.push_back(right);
            }
            index += 1;
        }
    }
    Some(root)
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_sum_of_left_leaves() {
        assert_eq!(
            Solution::sum_of_left_leaves(tree![3, 9, 20, null, null, 15, 7]),
            24
        );
        assert_eq!(Solution::sum_of_left_leaves(tree![1]), 0);
    }
}
