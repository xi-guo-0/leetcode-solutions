struct Solution;

impl Solution {
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut nums = nums;
        let n = nums.len();
        nums.sort();
        let mut res: Vec<Vec<i32>> = Vec::new();
        for i in 0..n {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }
            for j in i + 1..n {
                if j > i + 1 && nums[j] == nums[j - 1] {
                    continue;
                }
                let t: i64 = (target) as i64 - (nums[i] + nums[j]) as i64;
                let mut x = j + 1;
                let mut y = n - 1;
                while x < y {
                    let m: i64 = (nums[x] + nums[y]) as i64;
                    if m < t {
                        x += 1;
                    } else if m > t {
                        y -= 1;
                    } else {
                        res.push(vec![nums[i], nums[j], nums[x], nums[y]]);
                        while x < y && nums[x] == nums[x + 1] {
                            x += 1;
                        }
                        while x < y && y < n - 1 && nums[y] == nums[y + 1] {
                            y -= 1;
                        }
                        x += 1;
                        y -= 1;
                    }
                }
            }
        }
        res
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn test_four_sum() {
        assert_eq!(
            Solution::four_sum(vec![1, 0, -1, 0, -2, 2], 0),
            vec![vec![-2, -1, 1, 2], vec![-2, 0, 0, 2], vec![-1, 0, 0, 1]]
        );
        assert_eq!(
            Solution::four_sum(vec![2, 2, 2, 2, 2], 8),
            vec![vec![2, 2, 2, 2]]
        );
    }
}
