class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> position(256, -1);
        int res = 0, left = -1;
        for (int i = 0; i < s.size(); ++i) {
            left = max(left, position[s[i]]);
            position[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};

