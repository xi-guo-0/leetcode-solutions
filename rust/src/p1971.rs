struct UF {
    parents: Vec<usize>,
}

impl UF {
    fn new(n: usize) -> Self {
        Self {
            parents: (0..n).collect(),
        }
    }

    fn is_connected(&mut self, x: usize, y: usize) -> bool {
        self.find(x) == self.find(y)
    }

    fn union(&mut self, x: usize, y: usize) {
        let l = std::cmp::min(x, y);
        let r = std::cmp::max(x, y);
        let pl = self.find(l);
        let pr = self.find(r);
        if pl != pr {
            self.parents[pr] = pl;
        }
    }

    fn find(&mut self, x: usize) -> usize {
        if x != self.parents[x] {
            self.parents[x] = self.find(self.parents[x]);
        }
        self.parents[x]
    }
}

impl Solution {
    pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool {
        let mut uf = edges.into_iter().fold(UF::new(n as usize), |mut uf, e| {
            let x = e[0] as usize;
            let y = e[1] as usize;
            uf.union(x, y);
            uf
        });
        uf.is_connected(source as usize, destination as usize)
    }
}
