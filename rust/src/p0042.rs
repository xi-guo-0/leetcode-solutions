struct Solution;

impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let n = height.len();
        let mut s = 0;
        let mut max_left = vec![0; n];
        let mut max_right = vec![0; n];
        for i in 1..n {
            max_left[i] = std::cmp::max(max_left[i - 1], height[i - 1]);
            max_right[n - 1 - i] = std::cmp::max(max_right[n - i], height[n - i]);
        }
        for i in 0..n {
            let h = std::cmp::min(max_left[i], max_right[i]);
            s += std::cmp::max(0, h - height[i]);
        }
        s
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_trap() {
        assert_eq!(Solution::trap(vec![0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]), 6);
        assert_eq!(Solution::trap(vec![4, 2, 0, 3, 2, 5]), 9);
    }
}
