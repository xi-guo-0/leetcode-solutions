impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        (k ^ nums.into_iter().reduce(std::ops::BitXor::bitxor).unwrap()).count_ones() as i32
    }
}
