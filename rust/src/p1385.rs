impl Solution {
    pub fn find_the_distance_value(arr1: Vec<i32>, mut arr2: Vec<i32>, d: i32) -> i32 {
        arr2.sort();
        let mut ans = 0;
        for x in arr1.into_iter() {
            match arr2.binary_search(&x) {
                Ok(i) => {}
                Err(i) => {
                    let found = (i < arr2.len() && (x - arr2[i]).abs() <= d)
                        || (1 <= i && (x - arr2[i - 1]).abs() <= d)
                        || (i + 1 < arr2.len() && (x - arr2[i + 1]).abs() <= d);

                    if !found {
                        ans += 1;
                    }
                }
            }
        }
        ans
    }
}
