use std::collections::HashSet;
impl Solution {
    pub fn find_max_k(mut nums: Vec<i32>) -> i32 {
        let set: HashSet<_> = nums.iter().map(|&x| x).collect();
        nums.sort_by(|a, b| b.cmp(a));
        for n in nums.iter() {
            if set.contains(&(-n)) {
                return *n;
            }
        }
        -1
    }
}
