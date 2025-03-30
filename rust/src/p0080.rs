struct Solution;

impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        if nums.len() <= 2 {
            nums.len() as i32
        } else {
            let mut k: usize = 2;
            for i in 2..nums.len() {
                if nums[k - 2] != nums[i] {
                    nums[k] = nums[i];
                    k += 1;
                }
            }
            k as i32
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_remove_duplicates() {
        let mut nums = vec![1, 1, 1, 2, 2, 3];
        assert_eq!(Solution::remove_duplicates(&mut nums), 5);
        let mut nums = vec![0, 0, 1, 1, 1, 1, 2, 3, 3];
        assert_eq!(Solution::remove_duplicates(&mut nums), 7);
    }
}
