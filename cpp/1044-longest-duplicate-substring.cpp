#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  string longestDupSubstring(string s) {
    const uint64_t base = 131;
    vector<uint64_t> power(s.size(), 1);
    for (size_t i = 1; i < s.size(); ++i) {
      power[i] = power[i - 1] * base;
    }

    int left = 1, right = s.size() - 1;
    string result;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      auto duplicate = findDuplicateSubstring(s, mid, power);
      if (!duplicate.empty()) {
        if (duplicate.size() > result.size()) {
          result = duplicate;
        }
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return result;
  }

private:
  string findDuplicateSubstring(const string &s, int len,
                                const vector<uint64_t> &power) {
    const uint64_t base = 131;
    unordered_set<uint64_t> hashes;
    uint64_t currentHash = 0;

    for (int i = 0; i < len; ++i) {
      currentHash = currentHash * base + s[i];
    }

    hashes.insert(currentHash);

    for (size_t i = len; i < s.size(); ++i) {
      currentHash = currentHash - power[len - 1] * s[i - len];
      currentHash = currentHash * base + s[i];

      if (hashes.find(currentHash) != hashes.end()) {
        return s.substr(i - len + 1, len);
      }

      hashes.insert(currentHash);
    }

    return "";
  }
};

int main() { return 0; }