impl Solution {
    pub fn row_and_maximum_ones(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ans: Vec<i32> = vec![0, 0];
        for (i, row) in mat.into_iter().enumerate() {
            let cnt = row.into_iter().filter(|x| *x == 1).count() as i32;
            if ans[1] < cnt {
                ans[0] = i as i32;
                ans[1] = cnt;
            }
        }
        ans
    }
}
