class Solution {
public:
    int numTrees(int n) {
        long long product = 1;
        for (long long i = 1; i <= n; i++) {
            product *= (n + i);
            product /= i;
        }        
        return product/(n + 1);
    }
};
