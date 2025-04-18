impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let n = numbers.len();
        let mut i = 0;
        let mut j = n - 1;
        while i < j {
            let s = numbers[i] + numbers[j];
            if s < target {
                i += 1;
            } else if (s > target) {
                j -= 1;
            } else {
                return vec![i as i32 + 1, j as i32 + 1];
            }
        }
        vec![-1, -1]
    }
}
