struct Trie {
    bool is_end;
    unordered_map<char, Trie *> links;
    void insert(const string& word) {
        Trie *cur = this;
        for (const char ch : word) {
            if (!cur->links.count(ch)) cur->links.insert({ch, new Trie()});
            cur = cur->links[ch];
        }
        cur->is_end = true;
    }
};

class Solution {
public:
    bool wordBreak(const string& s, const vector<string>& wordDict) {
        memo = vector<int>(s.size(), 0);
        root = new Trie();
        for (const auto& w : wordDict)
            root->insert(w);
        return solve(s, 0, s.size());
    }
    
private:
    Trie* root;
    vector<int> memo;
    bool solve(const string& s, const int first, const int last) {
        if (first == last) return true;
        else if (memo[first]) return 0 < memo[first];
        Trie* node = root;
        for (int i = first; i != last; ++i) {
            if (!node->links.count(s[i])) break;
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
