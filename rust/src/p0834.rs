use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn sum_of_distances_in_tree(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
        let mut graph: HashMap<i32, Vec<i32>> = HashMap::new();
        let mut count: Vec<i32> = vec![0; n as usize];
        let mut res: Vec<i32> = vec![0; n as usize];

        for edge in edges {
            let u = edge[0];
            let v = edge[1];
            graph.entry(u).or_insert_with(Vec::new).push(v);
            graph.entry(v).or_insert_with(Vec::new).push(u);
        }

        fn dfs1(
            cur: i32,
            parent: i32,
            graph: &HashMap<i32, Vec<i32>>,
            count: &mut Vec<i32>,
            res: &mut Vec<i32>,
        ) {
            count[cur as usize] = 1;
            if let Some(children) = graph.get(&cur) {
                for &child in children {
                    if child != parent {
                        dfs1(child, cur, graph, count, res);
                        count[cur as usize] += count[child as usize];
                        res[cur as usize] += res[child as usize] + count[child as usize];
                    }
                }
            }
        }

        fn dfs2(
            cur: i32,
            parent: i32,
            n: i32,
            count: &Vec<i32>,
            res: &mut Vec<i32>,
            graph: &HashMap<i32, Vec<i32>>,
        ) {
            if let Some(children) = graph.get(&cur) {
                for &child in children {
                    if child != parent {
                        res[child as usize] = res[cur as usize] + n - 2 * count[child as usize];
                        dfs2(child, cur, n, count, res, graph);
                    }
                }
            }
        }

        dfs1(0, -1, &graph, &mut count, &mut res);
        dfs2(0, -1, n, &count, &mut res, &graph);

        res
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_sum_of_distances_in_tree() {
        assert_eq!(
            Solution::sum_of_distances_in_tree(
                6,
                vec![vec![0, 1], vec![0, 2], vec![2, 3], vec![2, 4], vec![2, 5]]
            ),
            vec![8, 12, 6, 10, 10, 10]
        );
        assert_eq!(Solution::sum_of_distances_in_tree(1, vec![]), vec![0]);
        assert_eq!(
            Solution::sum_of_distances_in_tree(2, vec![vec![1, 0]]),
            vec![1, 1]
        );
    }
}
