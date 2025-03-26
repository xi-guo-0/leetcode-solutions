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
    pub fn smallest_from_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> String {
        let mut smallest_string = "~".to_owned();
        let mut stack = vec![(root.unwrap(), vec![])];
        while !stack.is_empty() {
            let (node, mut letters) = stack.pop().unwrap();
            let node_ref = node.borrow();
            letters.insert(0, node_ref.val as u8 + b'a');
            if node_ref.left.is_none() && node_ref.right.is_none() {
                let string = String::from_utf8(letters).unwrap();
                smallest_string = smallest_string.min(string);
            } else {
                if let Some(left) = node_ref.left.clone() {
                    stack.push((left, letters.clone()));
                }
                if let Some(right) = node_ref.right.clone() {
                    stack.push((right, letters));
                }
            }
        }
        smallest_string
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
    fn test_smallest_from_leaf() {
        let root = build_tree(vec![
            Some(0),
            Some(1),
            Some(2),
            Some(3),
            Some(4),
            Some(3),
            Some(4),
        ]);
        assert_eq!(Solution::smallest_from_leaf(root), "dba");

        let root = build_tree(vec![
            Some(25),
            Some(1),
            Some(3),
            Some(1),
            Some(3),
            Some(0),
            Some(2),
        ]);
        assert_eq!(Solution::smallest_from_leaf(root), "adz");

        let root = build_tree(vec![
            Some(2),
            Some(2),
            Some(1),
            None,
            Some(1),
            Some(0),
            None,
            Some(0),
        ]);
        assert_eq!(Solution::smallest_from_leaf(root), "abc");
    }
}
