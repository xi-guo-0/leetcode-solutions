struct Solution;

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut k = 0;
        for i in 0..nums.len() {
            if nums[i] != val {
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
    fn test_remove_element() {
        let mut nums = vec![3, 2, 2, 3];
        assert_eq!(Solution::remove_element(&mut nums, 3), 2);
        let mut nums = vec![0, 1, 2, 2, 3, 0, 4, 2];
        assert_eq!(Solution::remove_element(&mut nums, 2), 5);
    }
}
