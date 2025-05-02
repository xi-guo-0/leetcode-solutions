use std::cmp::Ordering;

struct Solution;

impl Solution {
    pub fn push_dominoes(dominoes: String) -> String {
        let len = dominoes.len();
        let bytes = dominoes.as_bytes();
        let mut forces = vec![0; len];
        let mut force = None;
        for i in 0..len {
            force = match bytes[i] {
                b'R' => Some(0),
                b'.' => force.map(|f| f + 1),
                _ => None,
            };
            forces[i] -= force.unwrap_or(len as i32);
        }
        force = None;
        for i in (0..len).rev() {
            force = match bytes[i] {
                b'L' => Some(0),
                b'.' => force.map(|f| f + 1),
                _ => None,
            };
            forces[i] += force.unwrap_or(len as i32);
        }
        forces
            .iter()
            .map(|&f| match f.cmp(&0) {
                Ordering::Less => 'L',
                Ordering::Equal => '.',
                Ordering::Greater => 'R',
            })
            .collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_push_dominoes() {
        assert_eq!(
            Solution::push_dominoes(".L.R...LR..L..".to_string()),
            "LL.RR.LLRRLL.."
        );
    }
}
