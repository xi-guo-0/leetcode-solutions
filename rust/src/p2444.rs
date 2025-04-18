impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, min_k: i32, max_k: i32) -> i64 {
        // [1] storage for indices of the last encountered
        //     types of numbers (min_k, max_k and out-of-range)
        let mut last_out: i64 = -1;
        let mut last_min: i64 = -1;
        let mut last_max: i64 = -1;

        let mut count: i64 = 0;

        for (i, n) in nums.into_iter().enumerate() {
            if min_k <= n && n <= max_k {
                if n == min_k {
                    last_min = i as i64;
                }
                if n == max_k {
                    last_max = i as i64;
                }

                // [2] magic happens here: if on current iteration the
                //     number 'n' falls in a given range, then we:
                //     - first, ensure that both min_k and max_k have been
                //       seen after the last ouf-range-number;
                //     - second, we add all intervals that start right after
                //       the last out-of-range number and incorporate
                //       at least one min_k and at least one max_k
                count += 0i64.max(last_min.min(last_max) - last_out);
            } else {
                last_out = i as i64;
            }
        }

        return count;
    }
}
