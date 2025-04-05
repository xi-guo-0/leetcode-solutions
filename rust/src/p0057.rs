struct Solution;

impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let l = match intervals.binary_search_by_key(&new_interval[0], |x| x[1]) {
            Ok(pos) => pos,
            Err(pos) => pos,
        };
        let r = match intervals.binary_search_by_key(&(new_interval[1] + 1), |x| x[0]) {
            Ok(pos) => pos,
            Err(pos) => pos,
        };
        let min_start = new_interval[0].min(intervals.get(l).unwrap_or(&new_interval)[0]);
        let max_end = new_interval[1].max(intervals.get(r - 1).unwrap_or(&new_interval)[1]);
        intervals
            .iter()
            .take(l)
            .cloned()
            .chain(std::iter::once(vec![min_start, max_end]))
            .chain(intervals.iter().skip(r).cloned())
            .collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_insert() {
        assert_eq!(
            Solution::insert(vec![vec![1, 3], vec![6, 9]], vec![2, 5]),
            vec![vec![1, 5], vec![6, 9]]
        );
        assert_eq!(
            Solution::insert(
                vec![
                    vec![1, 2],
                    vec![3, 5],
                    vec![6, 7],
                    vec![8, 10],
                    vec![12, 16]
                ],
                vec![4, 8]
            ),
            vec![vec![1, 2], vec![3, 10], vec![12, 16]]
        );
    }
}
