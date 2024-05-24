std::vector<std::string> StringSplit(const std::string &sentence) {
  std::vector<std::string> ans{""};
  for (const char c : sentence) {
    if (isblank(c)) {
      ans.emplace_back("");
    } else {
      ans.back().push_back(c);
    }
  }
  return ans;
}

std::string StringJoin(const std::vector<std::string> &ws) {
  std::ostringstream oss;
  if (!ws.empty()) {
    oss << ws.front();
    for (int i = 1; i < ws.size(); ++i) {
      oss << " " << ws[i];
    }
  }
  return oss.str();
}

struct TNode {
  bool is_end_;
  std::map<char, TNode *> children_;
  explicit TNode() : is_end_(false) {}
};

class Trie {
private:
  TNode root;

public:
  void Insert(const std::string &key) {
    TNode *p = &root;
    for (const char c : key) {
      if (!p->children_.count(c)) {
        p->children_[c] = new TNode;
      }
      p = p->children_[c];
    }
    p->is_end_ = true;
  }

  std::string Find(const std::string &key) {
    std::string ans;
    TNode *p = &root;
    for (const char c : key) {
      if (!p->children_.count(c)) {
        break;
      }
      ans.push_back(c);
      p = p->children_[c];
      if (p->is_end_) {
        return ans;
      }
    }
    return "";
  }
};

class Solution {
public:
  string replaceWords(vector<string> &dictionary, string sentence) {
    Trie trie;
    for (const auto &w : dictionary) {
      trie.Insert(w);
    }
    auto ws = StringSplit(sentence);
    for (auto &w : ws) {
      auto p = trie.Find(w);
      if (!p.empty()) {
        w = p;
      }
    }
    return StringJoin(ws);
  }
};
