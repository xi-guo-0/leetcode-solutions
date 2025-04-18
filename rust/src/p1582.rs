fn onlyone_column(row: &Vec<i32>) -> Option<usize> {
    let mut c: Option<usize> = None;
    for (i, d) in row.iter().enumerate() {
        if *d == 1 {
            if c.is_none() {
                c = Some(i)
            } else {
                return None;
            }
        }
    }
    c
}

impl Solution {
    pub fn num_special(mat: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let m = mat.len();
        let n = mat[0].len();
        for i in 0..m {
            if let Some(c) = onlyone_column(&mat[i]) {
                let mut osc = 0;
                for j in 0..m {
                    if mat[j][c] == 1 {
                        osc += 1;
                    }
                }
                if osc == 1 {
                    ans += 1;
                }
            }
        }
        ans
    }
}
