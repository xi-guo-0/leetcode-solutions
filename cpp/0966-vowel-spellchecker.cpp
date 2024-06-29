#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> spellchecker(vector<string> &wordlist,
                              vector<string> &queries) {
    unordered_set<string> exact_words(wordlist.begin(), wordlist.end());
    unordered_map<string, string> case_insensitive_map;
    unordered_map<string, string> vowel_error_map;
    for (const auto &word : wordlist) {
      string lower_case_word = to_lower(word);
      case_insensitive_map.emplace(lower_case_word, word);

      string vowel_error_word = mask_vowels(lower_case_word);
      vowel_error_map.emplace(vowel_error_word, word);
    }

    vector<string> ans;
    for (const auto &query : queries) {
      if (exact_words.count(query)) {
        ans.push_back(query);
      } else {
        string lower_case_query = to_lower(query);
        if (case_insensitive_map.count(lower_case_query)) {
          ans.push_back(case_insensitive_map[lower_case_query]);
        } else {
          string vowel_error_query = mask_vowels(lower_case_query);
          if (vowel_error_map.count(vowel_error_query)) {
            ans.push_back(vowel_error_map[vowel_error_query]);
          } else {
            ans.push_back("");
          }
        }
      }
    }
    return ans;
  }

private:
  string to_lower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
  }

  string mask_vowels(string s) {
    for (char &c : s) {
      if (is_vowel(c)) {
        c = '*';
      }
    }
    return s;
  }

  bool is_vowel(char c) {
    static const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
    return vowels.count(c);
  }
};

int main() { return 0; }
