impl Solution {
    pub fn result_array(nums: Vec<i32>) -> Vec<i32> {
        let mut arr1 = vec![nums[0]];
        let mut arr2 = vec![nums[1]];
        for i in 2..nums.len() {
            let x = arr1.last().unwrap();
            let y = arr2.last().unwrap();
            if x > y {
                arr1.push(nums[i]);
            } else {
                arr2.push(nums[i]);
            }
        }
        arr1.extend(arr2.into_iter());
        arr1
    }
}
