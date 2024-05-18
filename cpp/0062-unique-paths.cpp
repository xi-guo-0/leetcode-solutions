class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;
        n--;
        int lower = min(m, n);
        int higher = max(m, n);
        long long result = 1;
        for (long long i = 1; i <= lower; i++) {
            result *= (higher + i);
            result /= i;
        }
        return result;
    }
};
