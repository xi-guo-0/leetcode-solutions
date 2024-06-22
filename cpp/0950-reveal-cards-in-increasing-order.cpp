#include <vector>

using namespace std;

class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int> &deck) {
    if (deck.size() < 2) {
      return deck;
    }
    sort(deck.begin(), deck.end());
    const int n = deck.size();
    const int pivot = -1;
    vector<int> result(n, pivot);
    result[0] = deck[0];
    int j = 1;
    for (int i = 1; i < n - 1; i++) {
      while (result[j] != pivot)
        j = (j + 1) % n;
      j = (j + 1) % n;
      while (result[j] != pivot)
        j = (j + 1) % n;
      result[j] = deck[i];
    }
    while (result[j] != pivot)
      j = (j + 1) % n;
    result[j] = deck[n - 1];
    return result;
  }
};

int main() { return 0; }
