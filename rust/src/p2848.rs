impl Solution {
    pub fn number_of_points(nums: Vec<Vec<i32>>) -> i32 {
        let mut c = [0; 128];
        for p in nums.into_iter() {
            for i in p[0]..(p[1] + 1) {
                c[i as usize] = 1;
            }
        }
        c.iter().sum()
    }
}
