class Solution {
public:
    int divide(int dividend, int divisor) {
        long long f = divisor < 0 ? -(long long)dividend : dividend;
        long long s = divisor < 0 ? -(long long)divisor : divisor;

        if (INT_MAX <= f/s || f/s <= INT_MIN) {
            if (f/s < 0) return INT_MIN;
            else return INT_MAX;
        }
        return f/s;
    }
};
