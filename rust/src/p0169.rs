impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut pivot = nums[0];
        let mut cnt = 1;
        for i in 1..nums.len() {
            if pivot == nums[i] {
                cnt += 1;
            } else {
                cnt -= 1;
                if cnt == 0 {
                    pivot = nums[i];
                    cnt = 1;
                }
            }
        }
        pivot
    }
}
