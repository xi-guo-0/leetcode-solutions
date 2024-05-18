struct Trie {
  bool is_end;
  unordered_map<char, Trie *> links;
  void insert(const string &word) {
    Trie *cur = this;
    for (const char ch : word) {
      if (!cur->links.count(ch))
        cur->links.insert({ch, new Trie()});
      cur = cur->links[ch];
    }
    cur->is_end = true;
  }
};

class Solution139 {
public:
  bool wordBreak(const string &s, const vector<string> &wordDict) {
    memo = vector<int>(s.size(), 0);
    root = new Trie();
    for (const auto &w : wordDict)
      root->insert(w);
    return solve(s, 0, s.size());
  }

private:
  Trie *root;
  vector<int> memo;
  bool solve(const string &s, const int first, const int last) {
    if (first == last)
      return true;
    else if (memo[first])
      return 0 < memo[first];
    Trie *node = root;
    for (int i = first; i != last; ++i) {
      if (!node->links.count(s[i]))
        break;
      node = node->links[s[i]];
      if (node->is_end && solve(s, i + 1, last)) {
        memo[first] = 1;
        return true;
      }
    }
    memo[first] = -1;
    return false;
  }
};

class Solution {
public:
  vector<string> wordBreak(const string &s, const vector<string> &wordDict) {
    if (!Solution139().wordBreak(s, wordDict))
      return ans;
    root = new Trie();
    ans = vector<string>();
    part = vector<string>();
    for (const auto &w : wordDict)
      root->insert(w);
    britain(s, 0);
    return ans;
  }

private:
  Trie *root;
  vector<string> ans;
  vector<string> part;

  void britain(const string &s, const int first) {
    if (first == s.size()) {
      ostringstream os;
      os << part.front();
      for (int i = 1; i < part.size(); i++)
        os << " " << part[i];
      ans.push_back(os.str());
    }
    Trie *node = root;
    for (int i = first; i != s.size(); ++i) {
      if (!node->links.count(s[i]))
        break;
      node = node->links[s[i]];
      if (node->is_end) {
        part.push_back(s.substr(first, i - first + 1));
        britain(s, i + 1);
        part.pop_back();
      }
    }
  }
};
