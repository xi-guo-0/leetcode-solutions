struct Trie {
  bool is_end;
  int val;
  unordered_map<char, Trie *> links;
  void insert(const string &word, const int val) {
    Trie *cur = this;
    for (const char ch : word) {
      if (!cur->links.count(ch))
        cur->links.insert({ch, new Trie()});
      cur = cur->links[ch];
    }
    cur->val = val;
    cur->is_end = true;
  }

  int eval() {
    Trie *cur = this;
    int v = cur->is_end ? cur->val : 0;
    for (const auto &l : links)
      v += l.second->eval();
    return v;
  }
};

class MapSum {
public:
  MapSum() { root = new Trie(); }

  void insert(string key, int val) { root->insert(key, val); }

  int sum(string prefix) {
    Trie *node = root;
    for (const char ch : prefix) {
      if (!node->links.count(ch))
        return 0;
      node = node->links[ch];
    }
    return node->eval();
  }

private:
  Trie *root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
