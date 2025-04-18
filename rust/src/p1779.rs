fn filter_valid(x: i32, y: i32, points: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    points
        .into_iter()
        .enumerate()
        .map(|(i, mut c)| {
            c.push(i as i32);
            c
        })
        .filter(|p| p[0] == x || p[1] == y)
        .collect()
}

fn dis(x: i32, y: i32, p: &[i32]) -> i32 {
    (p[0] - x).abs() + (p[1] - y).abs()
}

impl Solution {
    pub fn nearest_valid_point(x: i32, y: i32, points: Vec<Vec<i32>>) -> i32 {
        let mut points = filter_valid(x, y, points);
        points.sort_by(|a, b| dis(x, y, a).cmp(&dis(x, y, b)));
        if points.is_empty() {
            -1
        } else {
            points[0][2]
        }
    }
}
