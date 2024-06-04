#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<char, int>> runLengthEncode(const string &str) {
  vector<pair<char, int>> result;
  for (char c : str) {
    if (result.empty() || result.back().first != c) {
      result.emplace_back(c, 1);
    } else {
      result.back().second++;
    }
  }
  return result;
}

bool isStretchy(const string &s, const string &word) {
  auto sRLE = runLengthEncode(s);
  auto wordRLE = runLengthEncode(word);
  if (sRLE.size() != wordRLE.size())
    return false;

  for (size_t i = 0; i < sRLE.size(); ++i) {
    if (sRLE[i].first != wordRLE[i].first)
      return false;
    int sCount = sRLE[i].second;
    int wCount = wordRLE[i].second;
    if (sCount < wCount || (sCount < 3 && sCount != wCount))
      return false;
  }
  return true;
}

class Solution {
public:
  int expressiveWords(const string &s, const vector<string> &words) {
    int count = 0;
    for (const auto &word : words) {
      if (isStretchy(s, word)) {
        count++;
      }
    }
    return count;
  }
};

int main() { return 0; }
