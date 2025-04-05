struct Solution;

impl Solution {
    pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = vec![];
        intervals.sort();
        ans.push(intervals[0].clone());
        for interval in (&intervals[1..intervals.len()]).into_iter() {
            let l = interval[0];
            let r = interval[1];
            let len = ans.len();
            let last = ans[len - 1][1];
            if l <= last {
                ans[len - 1][1] = std::cmp::max(last, r);
            } else {
                ans.push(vec![l, r]);
            }
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_merge() {
        assert_eq!(
            Solution::merge(vec![vec![1, 3], vec![2, 6], vec![8, 10], vec![15, 18]]),
            vec![vec![1, 6], vec![8, 10], vec![15, 18]]
        );
        assert_eq!(Solution::merge(vec![vec![1, 4], vec![4, 5]]), vec![[1, 5]]);
    }
}
