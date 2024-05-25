class Solution {
public:
  vector<string> topKFrequent(const vector<string> &words, int k) {
    unordered_map<string, int> dict;
    for (const auto &s : words)
      dict[s]++;
    vector<pair<string, int>> tmp(dict.begin(), dict.end());
    sort(tmp.begin(), tmp.end(),
         [](const pair<string, int> &a, const pair<string, int> &b) {
           return a.second != b.second ? a.second > b.second
                                       : a.first < b.first;
         });
    vector<string> ans;
    for (int i = 0; i < k; i++)
      ans.push_back(tmp[i].first);
    return ans;
  }
};
