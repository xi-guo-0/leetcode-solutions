impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        use std::collections::HashMap;
        let mut map: HashMap<i32, usize> = HashMap::new();
        for i in 0..nums.len() {
            if map.contains_key(&nums[i]) && *map.get(&nums[i]).unwrap() > 0 {
                return true;
            }
            *map.entry(nums[i]).or_default() += 1;
            if k as usize <= i {
                let j = i - k as usize;
                *map.entry(nums[j]).or_default() -= 1;
            }
        }
        false
    }
}
