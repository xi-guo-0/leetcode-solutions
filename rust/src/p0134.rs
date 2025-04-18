impl Solution {
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        let mut total: i32 = 0;
        let mut j: i32 = -1;
        let mut sum: i32 = 0;
        for i in 0..gas.len() {
            let income = gas[i] - cost[i];
            sum += income;
            total += income;
            if sum < 0 {
                j = i as i32;
                sum = 0;
            }
        }
        if 0 <= total {
            j + 1
        } else {
            -1
        }
    }
}
