use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn find_min_height_trees(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
        if edges.is_empty() {
            return vec![0i32];
        }
        let mut graph = Self::convert_to_graph(edges);
        let mut leaves: Vec<i32> = graph
            .iter()
            .filter(|(_, v)| v.len() == 1)
            .map(|(k, _)| *k)
            .collect();
        let mut cnt = n;
        while 2 < cnt {
            cnt -= leaves.len() as i32;
            let mut next_leaves: Vec<i32> = vec![];
            for leave in leaves.into_iter() {
                if let Some(mut value) = graph.remove(&leave) {
                    let tmp = value.pop().unwrap();
                    graph.get_mut(&tmp).unwrap().retain(|&x| x != leave);
                    if graph[&tmp].len() == 1 {
                        next_leaves.push(tmp)
                    }
                }
            }
            leaves = next_leaves;
        }
        leaves
    }

    fn convert_to_graph(edges: Vec<Vec<i32>>) -> HashMap<i32, Vec<i32>> {
        let mut graph: HashMap<i32, Vec<i32>> = HashMap::new();
        for v in edges.into_iter() {
            let x = v[0];
            let y = v[1];
            (*graph.entry(x.clone()).or_default()).push(y);
            (*graph.entry(y.clone()).or_default()).push(x);
        }
        graph
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_find_min_height_trees() {
        assert_eq!(
            Solution::find_min_height_trees(4, vec![vec![1, 0], vec![1, 2], vec![1, 3]]),
            vec![1]
        );
        let mut ans = Solution::find_min_height_trees(
            6,
            vec![vec![3, 0], vec![3, 1], vec![3, 2], vec![3, 4], vec![5, 4]],
        );
        ans.sort();
        assert_eq!(ans, vec![3, 4]);
    }
}
