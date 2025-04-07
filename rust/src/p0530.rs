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
    pub fn get_minimum_difference(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut min = std::i32::MAX;
        let mut prev = None;
        Self::inorder(root, &mut min, &mut prev);
        min
    }

    fn inorder(node: Option<Rc<RefCell<TreeNode>>>, min: &mut i32, prev: &mut Option<i32>) {
        if let Some(node) = node {
            let node = node.as_ref().borrow();

            Self::inorder(node.left.clone(), min, prev);
            if let Some(pr) = *prev {
                *min = std::cmp::min(*min, node.val - pr);
            }
            *prev = Some(node.val);
            Self::inorder(node.right.clone(), min, prev);
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

#[macro_export]
macro_rules! tree {
    () => {
        None
    };
    ($($x:tt),*) => {
        {
            let vec: Vec<Option<i32>> = vec![$(
                match stringify!($x) {
                    "null" => None,
                    num => Some(num.parse().unwrap()),
                }
            ),*];
            leetcode_input_to_tree(&vec)
        }
    };
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_get_minimum_difference() {
        assert_eq!(Solution::get_minimum_difference(tree![4, 2, 6, 1, 3]), 1);
        assert_eq!(
            Solution::get_minimum_difference(tree![1, 0, 48, null, null, 12, 49]),
            1
        );
    }
}
