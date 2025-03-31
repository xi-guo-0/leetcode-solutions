struct Solution;

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut k = 1;
        for i in 1..nums.len() {
            if nums[i - 1] != nums[i] {
                nums[k as usize] = nums[i];
                k += 1;
            }
        }
        k
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_remove_duplicates() {
        let mut nums = vec![1, 1, 2];
        assert_eq!(Solution::remove_duplicates(&mut nums), 2);
        let mut nums = vec![0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
        assert_eq!(Solution::remove_duplicates(&mut nums), 5);
    }
}
