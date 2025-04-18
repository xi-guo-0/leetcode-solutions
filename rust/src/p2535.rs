fn number_digit_sum(mut n: i32) -> i32 {
    let mut sum = 0;
    while n > 0 {
        sum += n % 10;
        n /= 10;
    }
    sum
}

impl Solution {
    pub fn difference_of_sum(nums: Vec<i32>) -> i32 {
        let element_sum = nums.iter().sum::<i32>();
        let digit_sum = nums.iter().map(|&x| number_digit_sum(x)).sum::<i32>();
        i32::abs(element_sum - digit_sum)
    }
}
