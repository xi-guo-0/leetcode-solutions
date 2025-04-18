/*
(x)(x+1)/2 * 2 = (n)(n+1)/2 + x
x^2 = (n)(n+1)/2
x = sqrt((n)(n+1)/2)
*/
impl Solution {
    pub fn pivot_integer(n: i32) -> i32 {
        let x_square = n * (n + 1) / 2;
        let mut i = 1;
        while i * i <= x_square {
            if i * i == x_square {
                return i;
            }
            i += 1
        }
        -1
    }
}
