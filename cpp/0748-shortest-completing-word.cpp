#include <algorithm>
#include <cctype>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string shortestCompletingWord(const string &licensePlate,
                                const vector<string> &words) {
    vector<string> might;
    map<char, int> license;

    for (char ch : licensePlate) {
      ch = tolower(ch);
      if (isalpha(ch)) {
        if (license.count(ch)) {
          license[ch]++;
        } else {
          license[ch] = 1;
        }
      }
    }

    for (const auto &word : words) {
      bool isMatch = true;
      map<char, int> m;

      for (const char ch : word) {
        if (m.count(ch)) {
          m[ch]++;
        } else {
          m[ch] = 1;
        }
      }

      for (const auto &p : license) {
        const char ch = p.first;
        const int n = p.second;
        if (!m.count(ch) || m[ch] < n) {
          isMatch = false;
          break;
        }
      }

      if (isMatch) {
        might.push_back(word);
      }
    }

    stable_sort(
        might.begin(), might.end(),
        [](const string &a, const string &b) { return a.size() < b.size(); });

    return might.front();
  }
};

int main() { return 0; }
