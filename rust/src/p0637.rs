use std::cell::RefCell;
use std::collections::VecDeque;
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
    pub fn average_of_levels(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<f64> {
        let mut ans = vec![];
        let mut cur = VecDeque::new();
        let mut next = VecDeque::new();
        if root.is_some() {
            cur.push_back(root);
        }
        while !cur.is_empty() {
            let mut row = vec![];
            while !cur.is_empty() {
                let node = cur.pop_front().unwrap();
                if node.clone().unwrap().borrow().left.is_some() {
                    next.push_back(node.clone().unwrap().borrow().left.clone());
                }
                if node.clone().unwrap().borrow().right.is_some() {
                    next.push_back(node.clone().unwrap().borrow().right.clone());
                }
                row.push(node.unwrap().borrow().val);
            }
            let avg = row.iter().map(|&x| x as f64).sum::<f64>() / row.len() as f64;
            ans.push(avg);
            std::mem::swap(&mut cur, &mut next);
        }
        ans
    }
}

pub fn vec_to_tree(vec: &[Option<i32>], index: usize) -> Option<Rc<RefCell<TreeNode>>> {
    if index >= vec.len() || vec[index].is_none() {
        return None;
    }

    let mut node = TreeNode::new(vec[index].unwrap());
    node.left = vec_to_tree(vec, 2 * index + 1);
    node.right = vec_to_tree(vec, 2 * index + 2);

    Some(Rc::new(RefCell::new(node)))
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_average_of_levels() {
        assert_eq!(
            Solution::average_of_levels(vec_to_tree(
                &[Some(3), Some(9), Some(20), None, None, Some(15), Some(7)],
                0
            )),
            vec![3.00000, 14.50000, 11.00000]
        );
        assert_eq!(
            Solution::average_of_levels(vec_to_tree(
                &[Some(3), Some(9), Some(20), Some(15), Some(7)],
                0
            )),
            vec![3.00000, 14.50000, 11.00000]
        );
    }
}
