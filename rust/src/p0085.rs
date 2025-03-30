struct Solution;

impl Solution {
    pub fn maximal_rectangle(matrix: Vec<Vec<char>>) -> i32 {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut ans = 0;
        let mut heights = vec![0; n + 1];
        for r in 0..m {
            for c in 0..n {
                heights[c] = if matrix[r][c] == '1' {
                    heights[c] + 1
                } else {
                    0
                }
            }
            ans = std::cmp::max(ans, Self::largest_rectangle_area(&heights));
        }
        ans as i32
    }

    fn largest_rectangle_area(heights: &[usize]) -> usize {
        let mut stack = Vec::<usize>::new();
        let mut ans = 0;
        let mut i = 0;
        while i < heights.len() {
            if stack.is_empty() || heights[*stack.last().unwrap()] < heights[i] {
                stack.push(i);
                i += 1;
            } else {
                let temp = stack.pop().unwrap();
                let w = if stack.is_empty() {
                    i
                } else {
                    i - stack.last().unwrap() - 1
                };
                ans = std::cmp::max(ans, heights[temp] * w);
            }
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_maximal_rectangle() {
        assert_eq!(
            Solution::maximal_rectangle(vec![
                vec!['1', '0', '1', '0', '0'],
                vec!['1', '0', '1', '1', '1'],
                vec!['1', '1', '1', '1', '1'],
                vec!['1', '0', '0', '1', '0'],
            ]),
            6
        );
        assert_eq!(Solution::maximal_rectangle(vec![vec!['0']]), 0);
        assert_eq!(Solution::maximal_rectangle(vec![vec!['1']]), 1);
    }
}
