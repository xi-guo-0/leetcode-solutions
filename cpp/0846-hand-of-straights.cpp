#include <algorithm>
#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool isNStraightHand(vector<int> &hand, int groupSize) {
    if (hand.size() % groupSize != 0) {
      return false;
    }

    std::unordered_map<int, int> cardCount;
    for (int card : hand) {
      cardCount[card] += 1;
    }

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (const auto &entry : cardCount) {
      minHeap.push(entry.first);
    }

    while (!minHeap.empty()) {
      int start = minHeap.top();
      for (int i = 0; i < groupSize; ++i) {
        int card = start + i;
        if (cardCount[card] == 0)
          return false;
        if (--cardCount[card] == 0) {

          if (card != minHeap.top())
            return false;
          minHeap.pop();
        }
      }
    }

    return true;
  }
};

int main() { return 0; }
