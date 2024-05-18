class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> values(n);
        iota(values.begin(), values.end(), 1);
        
        vector<bool> select(n, false);
        fill_n(select.begin(), k, true);
        
        do {
            vector<int> one(k);
            for (int i = 0, index = 0; i < n; i++)
                if (select[i])
                    one[index++] = values[i];
            result.push_back(one);
        } while (prev_permutation(select.begin(), select.end()));
        return result;
    }
};
