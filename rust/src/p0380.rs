use rand::prelude::IteratorRandom;
use std::collections::HashSet;

struct Solution;

struct RandomizedSet {
    set: HashSet<i32>,
    rng: rand::rngs::ThreadRng,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedSet {
    fn new() -> Self {
        Self {
            set: HashSet::new(),
            rng: rand::thread_rng(),
        }
    }

    fn insert(&mut self, val: i32) -> bool {
        self.set.insert(val)
    }

    fn remove(&mut self, val: i32) -> bool {
        self.set.remove(&val)
    }

    fn get_random(&mut self) -> i32 {
        *self.set.iter().choose(&mut self.rng).unwrap()
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * let obj = RandomizedSet::new();
 * let ret_1: bool = obj.insert(val);
 * let ret_2: bool = obj.remove(val);
 * let ret_3: i32 = obj.get_random();
 */

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_can_construct() {
        let mut rs = RandomizedSet::new();
        assert_eq!(rs.insert(1), true);
        assert_eq!(rs.remove(2), false);
        assert_eq!(rs.insert(2), true);
        let random_val = rs.get_random();
        assert!(random_val == 1 || random_val == 2);
        assert_eq!(rs.remove(1), true);
        assert_eq!(rs.insert(2), false);
        assert_eq!(rs.get_random(), 2);
    }
}
