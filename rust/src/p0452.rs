struct Solution;

impl Solution {
    pub fn find_min_arrow_shots(mut points: Vec<Vec<i32>>) -> i32 {
        points.sort();
        let mut ans = 0i32;
        let mut i = 0usize;
        while i < points.len() {
            let mut p = points[i].clone();
            let mut j = i + 1;
            while j < points.len() && p[0] < points[j][1] && points[j][0] <= p[1] {
                p[0] = std::cmp::max(p[0], points[j][0]);
                p[1] = std::cmp::min(p[1], points[j][1]);
                j += 1;
            }
            ans += 1;
            i = j;
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_find_min_arrow_shots() {
        assert_eq!(
            Solution::find_min_arrow_shots(vec![vec![10, 16], vec![2, 8], vec![1, 6], vec![7, 12]]),
            2
        );
        assert_eq!(
            Solution::find_min_arrow_shots(vec![vec![1, 2], vec![3, 4], vec![5, 6], vec![7, 8]]),
            4
        );
        assert_eq!(
            Solution::find_min_arrow_shots(vec![vec![1, 2], vec![2, 3], vec![3, 4], vec![4, 5]]),
            2
        );
    }
}
