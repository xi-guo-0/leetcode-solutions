class Trie {
public:
  /** Initialize your data structure here. */
  Trie() {
    memset(links, 0, sizeof(links));
    isEnd = false;
  }

  /** Inserts a word into the trie. */
  void insert(const string &word) {
    Trie *cur = this;
    for (const char ch : word) {
      const int t = ch - 'a';
      if (cur->links[t] == nullptr) {
        cur->links[t] = new Trie();
      }
      cur = cur->links[t];
    }
    cur->isEnd = true;
  }

  /** Returns if the word is in the trie. */
  bool search(const string &word) {
    Trie *cur = this;
    for (const char ch : word) {
      if (cur != nullptr)
        cur = cur->links[ch - 'a'];
    }
    return cur && cur->isEnd;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(const string &prefix) {
    Trie *cur = this;
    for (const char ch : prefix) {
      if (cur != nullptr)
        cur = cur->links[ch - 'a'];
    }
    return cur != nullptr;
  }

private:
  Trie *links[26];
  bool isEnd;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
