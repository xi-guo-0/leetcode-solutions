class Solution {
public:
  string removeDuplicateLetters(string s) {
    unordered_map<char, int> last_occur;
    unordered_set<char> gained;
    vector<char> ans;
    for (int i = 0; i < s.size(); ++i)
      last_occur[s[i]] = i;
    for (int i = 0; i < s.size(); ++i) {
      if (gained.count(s[i]))
        continue;
      while (!ans.empty() && s[i] < ans.back() && i < last_occur[ans.back()]) {
        gained.erase(ans.back());
        ans.pop_back();
      }
      ans.push_back(s[i]);
      gained.insert(s[i]);
    }
    return string(ans.begin(), ans.end());
  }
};
