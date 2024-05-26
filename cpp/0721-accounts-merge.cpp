#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> accountsMerge(const vector<vector<string>> &accounts) {
    if (accounts.empty())
      return vector<vector<string>>();
    const int n = accounts.size();
    vector<int> p(n);
    unordered_set<string> unique_emails;
    unordered_multimap<string, int> dict;
    generate(p.begin(), p.end(), [i = 0]() mutable { return i++; });
    auto find = [&p](int x) {
      while (x != p[x])
        x = p[x] = p[p[x]];
      return x;
    };
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < accounts[i].size(); ++j) {
        unique_emails.insert(accounts[i][j]);
        dict.insert({accounts[i][j], i});
      }
    }
    for (const auto &email : unique_emails) {
      if (1 < dict.count(email)) {
        auto range = dict.equal_range(email);
        vector<int> users;
        for (auto it = range.first; it != range.second; ++it)
          users.push_back(it->second);
        sort(users.begin(), users.end());
        for (int i = 1; i < users.size(); ++i)
          p[find(users[i - 1])] = find(users[i]);
        dict.erase(email);
      }
    }
    vector<vector<string>> ans(accounts.size());
    for (int i = 0; i < accounts.size(); ++i)
      ans[i].push_back(accounts[i].front());
    for (int i = 0; i < accounts.size(); ++i) {
      const int classification = find(i);
      for (int j = 1; j < accounts[i].size(); ++j)
        ans[classification].push_back(accounts[i][j]);
    }
    sort(ans.begin(), ans.end(),
         [](const auto &a, const auto &b) { return a.size() > b.size(); });
    while (!ans.empty() && ans.back().size() == 1)
      ans.pop_back();
    for (auto &line : ans) {
      sort(next(line.begin()), line.end());
      line.erase(unique(next(line.begin()), line.end()), line.end());
    }
    return ans;
  }
};

int main() { return 0; }
