use std::convert::TryInto;

type Bits = [i32; 32];

trait ToI32 {
    fn to_i32(&self) -> i32;
}

impl ToI32 for Bits {
    fn to_i32(&self) -> i32 {
        (0..32).map(|i| self[32 - i - 1] << i).sum()
    }
}

fn to_bits(x: i32) -> Bits {
    (0..32)
        .rev()
        .map(|n| (x >> n) & 1)
        .collect::<Vec<i32>>()
        .try_into()
        .unwrap()
}

fn add_bits(a: &Bits, b: &Bits) -> Bits {
    a.iter()
        .zip(b.iter())
        .map(|(x, y)| x + y)
        .collect::<Vec<i32>>()
        .try_into()
        .unwrap()
}

impl Solution {
    pub fn find_k_or(nums: Vec<i32>, k: i32) -> i32 {
        nums.into_iter()
            .map(to_bits)
            .fold(Default::default(), |acc, x| add_bits(&acc, &x))
            .map(|x| if k <= x { 1 } else { 0 })
            .to_i32()
    }
}
