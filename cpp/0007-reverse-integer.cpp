class Solution {
public:
    int reverse(int x) {
        while (x != 0 && x % 10 == 0)
            x /= 10;        
        if (-10 < x && x < 10) { return x; }
        long long a = llabs((long long)x);
        long long r = 0;
        while (a != 0) {
            r *= 10;
            r += a % 10;
            a /= 10;
        }
        r = x < 0 ? -r : r;
        if (r <= INT_MIN || r >= INT_MAX)
            r = 0;
        return r;
    }
};
