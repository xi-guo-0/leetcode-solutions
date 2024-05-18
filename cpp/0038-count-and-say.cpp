class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";
        int i, j, count;
        string s, prev = "11";
        for(i = 3; i <= n; i++) {
            s = "";
            count = 1;
            for(j = 1; j < prev.length(); j++) {
                if(prev[j] != prev[j-1]) {
                    s += to_string(count) + prev[j-1];
                    count = 1;
                }
                else count++;
            }
            s += to_string(count) + prev[j-1];
            prev = s;
        }
        return s;        
    }
};
