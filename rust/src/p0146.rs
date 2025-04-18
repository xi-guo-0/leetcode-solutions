use std::collections::{hash_map::Entry, HashMap};

struct Node {
    key: i32,
    val: i32,
    prev: usize,
    next: usize,
}
struct LRUCache {
    first: usize,
    last: usize,
    store: Vec<Node>,
    map: HashMap<i32, usize>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LRUCache {
    fn new(capacity: i32) -> Self {
        Self {
            store: Vec::with_capacity(capacity as usize),
            first: 0,
            last: 0,
            map: HashMap::new(),
        }
    }

    fn get(&mut self, key: i32) -> i32 {
        let Some(&i) = self.map.get(&key) else {
            return -1;
        };
        if i == self.last {
            return self.store[i].val;
        }
        if i != self.first {
            let prev = self.store[i].prev;
            self.store[prev].next = self.store[i].next;
        } else {
            self.first = self.store[i].next;
        }
        let next = self.store[i].next;
        self.store[next].prev = self.store[i].prev;

        self.store[self.last].next = i;
        self.store[i].prev = self.last;
        self.last = i;

        self.store[i].val
    }

    fn put(&mut self, key: i32, val: i32) {
        match self.map.entry(key) {
            Entry::Occupied(o) => {
                self.store[*o.get()].val = val;
                self.get(key);
            }
            Entry::Vacant(v) => {
                if self.store.capacity() > self.store.len() {
                    self.store.push(Node {
                        key,
                        val,
                        prev: self.last,
                        next: 0,
                    });
                    let i = self.store.len() - 1;
                    self.store[self.last].next = i;
                    self.last = i;
                    v.insert(i);
                    return;
                }

                v.insert(self.first);

                self.map.remove(&self.store[self.first].key);

                self.store[self.first].key = key;
                self.store[self.first].val = val;
                self.get(key);
            }
        }
    }
}
