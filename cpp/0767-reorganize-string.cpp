#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  struct CharFrequency {
    char character;
    int count;

    CharFrequency(char c, int cnt) : character(c), count(cnt) {}

    friend bool operator<(const CharFrequency &lhs, const CharFrequency &rhs) {
      return lhs.count < rhs.count;
    }
  };

public:
  string reorganizeString(const string &input) {
    unordered_map<char, int> frequencyMap;
    for (char ch : input) {
      ++frequencyMap[ch];
    }

    priority_queue<CharFrequency> maxHeap;
    for (const auto &[character, count] : frequencyMap) {
      maxHeap.emplace(character, count);
    }

    if ((input.size() + 1) / 2 < maxHeap.top().count) {
      return "";
    }

    string result(input.size(), ' ');
    int index = 0;
    while (!maxHeap.empty()) {
      CharFrequency topElement = maxHeap.top();
      maxHeap.pop();

      for (int i = 0; i < topElement.count; ++i) {
        if (index >= input.size()) {
          index = 1;
        }
        result[index] = topElement.character;
        index += 2;
      }
    }

    return result;
  }
};

int main() { return 0; }
