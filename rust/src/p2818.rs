impl Solution {
    pub fn maximum_score(nums: Vec<i32>, k: i32) -> i32 {
        let mut k = k;
        let scores: Vec<_> = nums
            .iter()
            .map(|&n| {
                let mut x = n;
                let mut c = 0;
                let mut p = 2;
                while p * p < x && x > 0 {
                    if x % p < 1 {
                        c += 1;
                        while x % p == 0 {
                            x /= p
                        }
                    };
                    p += 1
                }
                c + ((x > 1) as i32)
            })
            .collect();
        let (n, m, mut res) = (nums.len(), 1_000_000_007, 1);
        let (mut left, mut right, mut l, mut r) = (vec![-1; n], vec![n as i64; n], vec![], vec![]);
        for i in 0..n {
            let j = n - 1 - i;
            while l.len() > 0 && scores[l[l.len() - 1]] < scores[i] {
                l.pop();
            }
            while r.len() > 0 && scores[r[r.len() - 1]] <= scores[j] {
                r.pop();
            }
            if l.len() > 0 {
                left[i] = l[l.len() - 1] as i64
            };
            if r.len() > 0 {
                right[j] = r[r.len() - 1] as i64
            }
            l.push(i);
            r.push(j)
        }
        let mut idx: Vec<_> = (0..n).collect();
        idx.sort_unstable_by_key(|&i| -nums[i]);
        for i in idx {
            let range = (i as i64 - left[i]) * (right[i] - i as i64);
            let (mut x, mut e) = (nums[i] as i64, range.min(k as i64));
            while e > 0 {
                if e & 1 > 0 {
                    res = (res * x) % m
                };
                e /= 2;
                x = (x * x) % m
            }
            k -= range as i32;
            if k < 1 {
                break;
            }
        }
        res as _
    }
}
