impl Solution {
    pub fn find_the_array_conc_val(nums: Vec<i32>) -> i64 {
        let mut ans: i64 = 0;
        for i in 0..((nums.len() + 1) / 2) {
            let j = nums.len() - i - 1;
            if i != j {
                ans += nums[j] as i64;
                let mut l = nums[i] as i64;
                let mut t = nums[j] as i64;
                while 0 < t {
                    l *= 10;
                    t /= 10;
                }
                ans += l;
            } else {
                ans += nums[i] as i64;
            }
        }
        ans
    }
}
