class Solution {
public:
    vector<vector<string>> partition(string s) {
        const int n = s.size();
        bool p[n][n];
        fill_n(&p[0][0], n * n, false);
        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++)
                p[i][j] = s[i] == s[j] && ((j - i < 2) || p[i + 1][j - 1]);
        
        vector<vector<string>> sub_palindromes[n];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (p[i][j]) {
                    const string palindrome = s.substr(i, j - i + 1);
                    if (j + 1 < n) {
                        for (auto v : sub_palindromes[j + 1]) {
                            v.insert(v.begin(), palindrome);
                            sub_palindromes[i].push_back(v);
                        }
                    } else {
                        sub_palindromes[i].push_back(vector<string>{palindrome});
                    }
                }
            }
        }
        return sub_palindromes[0];
    }
};
