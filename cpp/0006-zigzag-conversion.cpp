class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2)
            return s;
        string res;
        int base = (numRows-1)*2;
        for (int diff = 0; diff < numRows; ++diff) {
            for (int i = 0; i < s.size(); i += base) {
                if (0 <= i+diff && i+diff < s.size())
                    res += s[i+diff];
                if (diff != 0 && diff != numRows-1 && 0 <= i+base-diff && i+base-diff < s.size()) {
                    res += s[i+base-diff];
                }
            }
        }
        return res;
    }
    
};
