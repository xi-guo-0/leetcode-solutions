#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trie {
private:
  struct Node {
    int ch[26];
    int flag;

    Node() : flag(-1) { fill(ch, ch + 26, 0); }
  };

  vector<Node> tree;

public:
  Trie() { tree.emplace_back(Node()); }

  void insert(const string &s, int id) {
    int len = s.length(), add = 0;
    for (int i = 0; i < len; ++i) {
      int x = s[i] - 'a';
      if (tree[add].ch[x] == 0) {
        tree.emplace_back(Node());
        tree[add].ch[x] = tree.size() - 1;
      }
      add = tree[add].ch[x];
    }
    tree[add].flag = id;
  }

  vector<int> query(const string &s) {
    int len = s.length(), add = 0;
    vector<int> ret(len + 1, -1);
    for (int i = 0; i < len; ++i) {
      ret[i] = tree[add].flag;
      int x = s[i] - 'a';
      if (tree[add].ch[x] == 0) {
        return ret;
      }
      add = tree[add].ch[x];
    }
    ret[len] = tree[add].flag;
    return ret;
  }
};

class Solution {
private:
  Trie trie1;
  Trie trie2;

  vector<vector<int>> manacher(const string &s) {
    int n = s.length();
    string tmp = "#";
    for (int i = 0; i < n; ++i) {
      if (i > 0) {
        tmp += '*';
      }
      tmp += s[i];
    }
    tmp += '!';

    int m = n * 2;
    vector<int> len(m, 0);
    vector<vector<int>> ret(n, vector<int>(2, 0));
    int p = 0, maxn = -1;
    for (int i = 1; i < m; ++i) {
      len[i] = maxn >= i ? min(len[2 * p - i], maxn - i) : 0;
      while (tmp[i - len[i] - 1] == tmp[i + len[i] + 1]) {
        len[i]++;
      }
      if (i + len[i] > maxn) {
        p = i;
        maxn = i + len[i];
      }
      if (i - len[i] == 1) {
        ret[(i + len[i]) / 2][0] = 1;
      }
      if (i + len[i] == m - 1) {
        ret[(i - len[i]) / 2][1] = 1;
      }
    }
    return ret;
  }

public:
  vector<vector<int>> palindromePairs(vector<string> &words) {
    for (int i = 0; i < words.size(); ++i) {
      trie1.insert(words[i], i);
      string tmp = words[i];
      reverse(tmp.begin(), tmp.end());
      trie2.insert(tmp, i);
    }

    vector<vector<int>> ret;
    for (int i = 0; i < words.size(); ++i) {
      auto rec = manacher(words[i]);

      auto id1 = trie2.query(words[i]);
      string reversed_word = words[i];
      reverse(reversed_word.begin(), reversed_word.end());
      auto id2 = trie1.query(reversed_word);

      int m = words[i].length();

      int allId = id1[m];
      if (allId != -1 && allId != i) {
        ret.push_back({i, allId});
      }
      for (int j = 0; j < m; ++j) {
        if (rec[j][0] != 0) {
          int leftId = id2[m - j - 1];
          if (leftId != -1 && leftId != i) {
            ret.push_back({leftId, i});
          }
        }
        if (rec[j][1] != 0) {
          int rightId = id1[j];
          if (rightId != -1 && rightId != i) {
            ret.push_back({i, rightId});
          }
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
  vector<vector<int>> result = sol.palindromePairs(words);
  cout << "[";
  for (const auto &pair : result) {
    cout << "[" << pair[0] << ", " << pair[1] << "], ";
  }
  cout << "]" << endl;
  return 0;
}
