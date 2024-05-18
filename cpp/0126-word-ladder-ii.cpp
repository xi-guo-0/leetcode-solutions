class Solution {
private:
  unordered_map<string, vector<string>> graph; // word -> parents
  vector<vector<string>> answers;

public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {
    if (wordList.empty()) {
      return {};
    }
    graph.clear();
    answers.clear();

    unordered_set<string> dict(wordList.begin(), wordList.end());
    unordered_set<string> current_level({beginWord});
    unordered_set<string> next_level;

    // bfs: build graph
    bool found = false;
    while (!current_level.empty()) {
      for (auto it = current_level.begin(); it != current_level.end(); ++it) {
        string word = *it;
        dict.erase(word);
        for (int i = 0; i < word.size(); ++i) {
          char old = word[i];
          for (char c = 'a'; c <= 'z'; ++c) {
            if (c == old) {
              continue;
            }
            word[i] = c;
            if (dict.find(word) == dict.end()) {
              continue;
            }
            if (word == endWord) {
              found = true;
            }
            if (current_level.find(word) == current_level.end()) {
              next_level.insert(word);
              graph[word].emplace_back(*it);
            }
          }
          word[i] = old;
        }
      }
      if (found) {
        break;
      }
      current_level.swap(next_level);
      next_level.clear();
    }
    if (!found) {
      return {};
    }

    vector<string> ans;
    dfs(ans, beginWord, endWord);
    return answers;
  }

  void dfs(vector<string> &ans, string &beginWord, string &endWord) {
    ans.emplace_back(endWord);
    if (beginWord == endWord) {
      answers.push_back(vector<string>(ans.rbegin(), ans.rend()));
      return;
    }
    vector<string> &parents = graph[endWord];
    for (string &parent : parents) {
      dfs(ans, beginWord, parent);
      ans.pop_back();
    }
  }
};
