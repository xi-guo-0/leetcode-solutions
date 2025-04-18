impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        nums.iter()
            .fold(Ranges::new(), |mut acc, x| {
                acc.add(*x);
                acc
            })
            .ranges
            .iter()
            .map(|r| r.to_string())
            .collect()
    }
}

struct Ranges {
    ranges: Vec<Range>,
}

impl Ranges {
    pub fn new() -> Ranges {
        Ranges { ranges: Vec::new() }
    }

    pub fn add(&mut self, x: i32) {
        match self.ranges.last_mut() {
            Some(Range(lo, hi)) if *hi + 1 == x => *hi = x,
            _ => self.ranges.push(Range(x, x)),
        }
    }
}

struct Range(i32, i32);

use std::fmt;

impl fmt::Display for Range {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        if self.0 == self.1 {
            write!(f, "{}", self.0)
        } else {
            write!(f, "{}->{}", self.0, self.1)
        }
    }
}
