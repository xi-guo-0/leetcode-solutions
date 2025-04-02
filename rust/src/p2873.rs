struct Solution;

impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        let mut max_value: i64 = 0;
        for i in 0..n - 2 {
            for j in i + 1..n - 1 {
                for k in j + 1..n {
                    let value = (nums[i] - nums[j]) as i64 * nums[k] as i64;
                    max_value = max_value.max(value);
                }
            }
        }
        max_value
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_maximum_triplet_value() {
        assert_eq!(Solution::maximum_triplet_value(vec![12, 6, 1, 2, 7]), 77);
        assert_eq!(Solution::maximum_triplet_value(vec![1, 10, 3, 4, 19]), 133);
        assert_eq!(Solution::maximum_triplet_value(vec![1, 2, 3]), 0);
        assert_eq!(
            Solution::maximum_triplet_value(vec![1000000, 1, 1000000]),
            999999000000
        );
    }
}
