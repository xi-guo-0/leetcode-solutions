use std::collections::BTreeMap;
impl Solution {
    pub fn merge_arrays(nums1: Vec<Vec<i32>>, nums2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        nums1
            .into_iter()
            .chain(nums2)
            .fold(BTreeMap::new(), |mut map, kv| {
                *map.entry(kv[0]).or_default() += kv[1];
                map
            })
            .into_iter()
            .map(|(k, v)| vec![k, v])
            .collect()
    }
}
