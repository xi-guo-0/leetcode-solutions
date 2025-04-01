struct Solution;

impl Solution {
    pub fn next_permutation(nums: &mut Vec<i32>) {
        let n = nums.len();
        if n <= 1 {
            return;
        }
        let mut i = n - 1;
        while i > 0 && nums[i - 1] >= nums[i] {
            i -= 1;
        }
        if i > 0 {
            let mut j = n - 1;
            while nums[j] <= nums[i - 1] {
                j -= 1;
            }
            nums.swap(i - 1, j);
        }
        nums[i..].reverse();
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_next_permutation() {
        let mut nums = vec![1, 2, 3];
        Solution::next_permutation(&mut nums);
        assert_eq!(nums, vec![1, 3, 2]);

        let mut nums = vec![3, 2, 1];
        Solution::next_permutation(&mut nums);
        assert_eq!(nums, vec![1, 2, 3]);

        let mut nums = vec![1, 1, 5];
        Solution::next_permutation(&mut nums);
        assert_eq!(nums, vec![1, 5, 1]);
    }
}
