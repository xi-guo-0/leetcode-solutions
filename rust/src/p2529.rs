impl Solution {
    pub fn maximum_count(nums: Vec<i32>) -> i32 {
        let i = match nums.binary_search_by(|x| x.cmp(&-1)) {
            Ok(v) => {
                let mut t = v;
                while t + 1 < nums.len() && nums[t] == nums[t + 1] {
                    t += 1;
                }
                t + 1
            }
            Err(v) => v,
        };
        let j = match nums.binary_search_by(|x| x.cmp(&1)) {
            Ok(v) => {
                let mut t = v;
                while 0 < t && nums[t - 1] == nums[t] {
                    t -= 1;
                }
                t
            }
            Err(v) => v,
        };
        std::cmp::max(i, nums.len() - j) as i32
    }
}
