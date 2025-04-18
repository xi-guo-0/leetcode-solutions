fn count_ones(n: usize) -> i32 {
    let mut count = 0;
    let mut n = n;
    while n > 0 {
        n &= n - 1;
        count += 1;
    }
    count
}

impl Solution {
    pub fn sum_indices_with_k_set_bits(nums: Vec<i32>, k: i32) -> i32 {
        let mut sum = 0;
        for (i, v) in nums.iter().enumerate() {
            if count_ones(i) == k {
                sum += v;
            }
        }
        sum
    }
}
