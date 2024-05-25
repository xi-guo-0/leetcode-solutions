#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class MagicDictionary {
private:
  std::unordered_map<std::string, std::vector<std::string>> dict;

public:
  MagicDictionary() = default;

  void buildDict(const std::vector<std::string> &dictionary) {
    for (const auto &word : dictionary) {
      for (size_t i = 0; i < word.size(); ++i) {
        std::string key = word.substr(0, i) + '*' + word.substr(i + 1);
        dict[key].push_back(word);
      }
    }
  }

  bool search(const std::string &searchWord) {
    for (size_t i = 0; i < searchWord.size(); ++i) {
      std::string key =
          searchWord.substr(0, i) + '*' + searchWord.substr(i + 1);
      if (auto it = dict.find(key); it != dict.end()) {
        for (const auto &word : it->second) {
          if (word.size() == searchWord.size() && word != searchWord) {
            int diffCount = 0;
            for (size_t j = 0; j < word.size(); ++j) {
              if (word[j] != searchWord[j] && ++diffCount > 1)
                break;
            }
            if (diffCount == 1)
              return true;
          }
        }
      }
    }
    return false;
  }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
