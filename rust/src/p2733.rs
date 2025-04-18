use std::cmp;

fn maxmin(nums: &[i32]) -> (i32, i32) {
    let mut max = nums[0];
    let mut min = nums[0];
    for x in nums {
        max = cmp::max(max, *x);
        min = cmp::min(min, *x);
    }
    (max, min)
}

impl Solution {
    pub fn find_non_min_or_max(nums: Vec<i32>) -> i32 {
        let (max, min) = maxmin(&nums);
        for x in nums {
            if x != max && x != min {
                return x;
            }
        }
        -1
    }
}
