struct Solution;

fn get_digits_sum(mut x: i32) -> i32 {
    let mut ans = 0;
    while 0 < x {
        ans += x % 10;
        x /= 10;
    }
    ans
}

impl Solution {
    pub fn sum_of_the_digits_of_harshad_number(x: i32) -> i32 {
        let digits_sum = get_digits_sum(x);
        if x % digits_sum == 0 { digits_sum } else { -1 }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_sum_of_the_digits_of_harshad_number() {
        assert_eq!(Solution::sum_of_the_digits_of_harshad_number(18), 9);
        assert_eq!(Solution::sum_of_the_digits_of_harshad_number(23), -1);
    }
}
