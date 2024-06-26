class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int j = -1;
        for (int i = 0, sum = 0; i < gas.size(); i++) {
            const int net_income = gas[i] - cost[i];
            sum += net_income;
            total += net_income;
            if (sum < 0) {
                j = i;
                sum = 0;
            }
        }
        return total >= 0 ? j + 1 : -1;
    }
};
