use std::convert::TryInto;

type Bits = [bool; 32];

trait ToBits {
    fn to_bits(&self) -> Bits;
}

impl ToBits for i32 {
    fn to_bits(&self) -> Bits {
        (0..32)
            .map(|n| (self >> n) & 1 == 1)
            .collect::<Vec<bool>>()
            .try_into()
            .unwrap()
    }
}

impl Solution {
    pub fn even_odd_bit(n: i32) -> Vec<i32> {
        let bits = n.to_bits();
        let e = bits
            .iter()
            .enumerate()
            .filter(|(i, b)| i % 2 == 0 && **b)
            .count();
        let o = bits
            .iter()
            .enumerate()
            .filter(|(i, b)| i % 2 == 1 && **b)
            .count();
        vec![e as i32, o as i32]
    }
}
