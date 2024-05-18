class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        int n = strs[0].size();
        for (size_t i = 1; i < strs.size(); i++)
            for (size_t j = 0; j < n; j++)
                if (strs[i][j] != strs[0][j])
                    n = j;
        return strs[0].substr(0, n);
    }
};
