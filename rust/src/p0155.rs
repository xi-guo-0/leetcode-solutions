struct MinStack {
    s: Vec<i32>,
    m: Vec<i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {

    fn new() -> Self {
        MinStack {
            s: Vec::new(),
            m: Vec::new(),
        } 
    }
    
    fn push(&mut self, val: i32) {
        self.s.push(val);
        if self.m.is_empty() || val <= *self.m.last().unwrap() {
            self.m.push(val);
        }
    }
    
    fn pop(&mut self) {
        if let Some(v) = self.m.pop() {
            if v != *self.s.last().unwrap() {
                self.m.push(v);
            }
        }
        let _ = self.s.pop();
    }
    
    fn top(&self) -> i32 {
        *self.s.last().unwrap()
    }
    
    fn get_min(&self) -> i32 {
        *self.m.last().unwrap()
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack::new();
 * obj.push(val);
 * obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: i32 = obj.get_min();
 */
