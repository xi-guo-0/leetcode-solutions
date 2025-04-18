impl Solution {
    pub fn left_right_difference(nums: Vec<i32>) -> Vec<i32> {
        let sum = nums.iter().sum::<i32>();
        let mut left_sum = 0;
        let mut ans = Vec::<i32>::new();
        nums.into_iter().for_each(|x| {
            let right_sum = sum - x - left_sum;
            ans.push((left_sum - right_sum).abs());
            left_sum += x;
        });
        ans
    }
}
