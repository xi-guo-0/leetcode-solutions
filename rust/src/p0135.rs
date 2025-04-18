impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let n = ratings.len();
        let mut increment = vec![0i32; n];
        let mut inc = 1;
        for i in 1..n {
            if ratings[i - 1] < ratings[i] {
                increment[i] = inc;
                inc += 1;
            } else {
                inc = 1
            }
        }
        inc = 1;
        for i in (0..n - 1).rev() {
            if ratings[i] > ratings[i + 1] {
                increment[i] = std::cmp::max(inc, increment[i]);
                inc += 1;
            } else {
                inc = 1;
            }
        }
        n as i32 + increment.iter().sum::<i32>()
    }
}
