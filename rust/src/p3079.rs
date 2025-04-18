fn n2d(n: i32) -> Vec<i32> {
    n.to_string()
        .chars()
        .map(|c| c.to_digit(10).unwrap() as i32)
        .collect()
}

fn d2n(digits: Vec<i32>) -> i32 {
    digits.into_iter().fold(0, |acc, x| acc * 10 + x)
}

fn encrypt(n: i32) -> i32 {
    let ds = n2d(n);
    d2n(vec![*ds.iter().max().unwrap(); ds.len()])
}

impl Solution {
    pub fn sum_of_encrypted_int(nums: Vec<i32>) -> i32 {
        nums.into_iter().map(|n| encrypt(n)).sum()
    }
}
