class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> classification;
        vector<vector<string>> result;
        for (auto str : strs) {
            string s(str);
            sort(s.begin(), s.end());
            if (classification.find(s) == classification.end()) {
                classification.insert({s, classification.size()});
                result.push_back(move(vector<string>()));
            }
            result[classification[s]].push_back(str);
        }
        return result;
    }
};
