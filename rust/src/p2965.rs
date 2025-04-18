use std::collections::HashMap;

fn count_occurrences(grid: &Vec<Vec<i32>>) -> HashMap<i32, i32> {
    let mut map: HashMap<i32, i32> = HashMap::new();
    for row in grid.iter() {
        for x in (*row).iter() {
            *map.entry(x.clone()).or_default() += 1;
        }
    }
    map
}

impl Solution {
    pub fn find_missing_and_repeated_values(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let n = grid.len();
        let mut ans = vec![0, 0];
        let oc = count_occurrences(&grid);
        for i in 1..(n * n + 1) {
            if !oc.contains_key(&(i as i32)) {
                ans[1] = i as i32;
            } else if oc[&(i as i32)] == 2 {
                ans[0] = i as i32;
            }
        }
        ans
    }
}
