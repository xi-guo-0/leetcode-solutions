#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class TrieNode {
public:
  unordered_map<char, TrieNode *> children;
  bool isEndOfWord;
  TrieNode() : isEndOfWord(false) {}
};

class Trie {
public:
  TrieNode *root;
  Trie() { root = new TrieNode(); }

  bool insert(const string &word) {
    TrieNode *node = root;
    bool isNewWord = false;
    for (auto it = word.rbegin(); it != word.rend(); ++it) {
      char c = *it;
      if (node->children.find(c) == node->children.end()) {
        isNewWord = true;
        node->children[c] = new TrieNode();
      }
      node = node->children[c];
    }
    node->isEndOfWord = true;
    return isNewWord;
  }
};

class Solution {
public:
  int minimumLengthEncoding(vector<string> &words) {
    sort(words.begin(), words.end(), [](const string &a, const string &b) {
      return a.length() > b.length();
    });

    Trie trie;
    int totalLength = 0;

    for (const string &word : words) {
      if (trie.insert(word)) {
        totalLength += word.length() + 1;
      }
    }

    return totalLength;
  }
};

int main() { return 0; }
