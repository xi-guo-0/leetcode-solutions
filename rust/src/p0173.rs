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

use std::rc::Rc;
use std::cell::RefCell;

struct BSTIterator {
    cur: Option<Rc<RefCell<TreeNode>>>,
    stack: Vec<Option<Rc<RefCell<TreeNode>>>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl BSTIterator {
    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        Self {
            cur: root,
            stack: vec![],
        }
    }

    fn next(&mut self) -> i32 {
        while self.cur.is_some() {
            let cur = self.cur.take().unwrap();
            let left = cur.borrow_mut().left.take();
            self.stack.push(Some(cur));
            self.cur = left;
        }

        let cur = self.stack.pop().unwrap().unwrap();
        let val = cur.borrow().val;
        self.cur = cur.borrow_mut().right.take();
        val
    }

    fn has_next(&self) -> bool {
        self.cur.is_some() || !self.stack.is_empty()
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * let obj = BSTIterator::new(root);
 * let ret_1: i32 = obj.next();
 * let ret_2: bool = obj.has_next();
 */
