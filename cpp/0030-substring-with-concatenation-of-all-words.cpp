#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findSubstring(const string &s, const vector<string> &words) {
    if (s.empty() || words.empty() || words[0].empty() ||
        s.size() < words[0].size()) {
      return vector<int>();
    }
    const int one_word = words[0].size(), word_num = words.size(),
              sub_len = one_word * word_num;
    vector<int> ans;
    unordered_map<string, int> needs;
    for (const auto &word : words)
      ++needs[word];
    for (int offset = 0; offset < words[0].size(); ++offset) {
      unordered_map<string, int> has;
      int left = offset, right = left + sub_len;
      for (int i = left; i != right; i += one_word)
        ++has[s.substr(i, one_word)];
      if (is_match(needs, has))
        ans.push_back(left);
      for (; right + one_word <= s.size();
           left += one_word, right += one_word) {
        --has[s.substr(left, one_word)];
        ++has[s.substr(right, one_word)];
        if (is_match(needs, has))
          ans.push_back(left + one_word);
      }
    }
    return ans;
  }

private:
  bool is_match(unordered_map<string, int> &needs,
                unordered_map<string, int> &has) {
    for (const auto &need : needs)
      if (need.second != has[need.first])
        return false;
    return true;
  }
};

int main() {
  assert((Solution().findSubstring("barfoothefoobarman",
                                   vector<string>{"foo", "bar"}) ==
          vector<int>{}));
  return 0;
}
