#include <deque>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Trie {
public:
  Trie() : root(make_unique<TrieNode>()) {}

  void insert(const string &word) {
    TrieNode *node = root.get();
    for (auto it = word.rbegin(); it != word.rend(); ++it) {
      if (!node->children.count(*it)) {
        node->children[*it] = make_unique<TrieNode>();
      }
      node = node->children[*it].get();
    }
    node->isEnd = true;
  }

  bool search(const deque<char> &stream) const {
    const TrieNode *node = root.get();
    for (const auto &ch : stream) {
      if (!node->children.count(ch)) {
        return false;
      }
      node = node->children.at(ch).get();
      if (node->isEnd) {
        return true;
      }
    }
    return false;
  }

private:
  struct TrieNode {
    unordered_map<char, unique_ptr<TrieNode>> children;
    bool isEnd = false;
  };

  unique_ptr<TrieNode> root;
};

class StreamChecker {
public:
  StreamChecker(vector<string> &words) : trie(make_unique<Trie>()) {
    for (const auto &word : words) {
      trie->insert(word);
    }
  }

  bool query(char letter) {
    stream.push_front(letter);
    return trie->search(stream);
  }

private:
  unique_ptr<Trie> trie;
  deque<char> stream;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main() { return 0; }
