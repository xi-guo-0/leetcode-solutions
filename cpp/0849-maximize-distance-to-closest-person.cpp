#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxDistToClosest(const vector<int> &seats) {
    int result = 0;
    if (seats[0] == 0) {
      int p = distance(seats.begin(), find(seats.begin(), seats.end(), 1));
      result = max(result, p);
    }
    if (seats[seats.size() - 1] == 0) {
      int p = distance(seats.rbegin(), find(seats.rbegin(), seats.rend(), 1));
      result = max(result, p);
    }
    for (int i = 0; i < seats.size(); i++) {
      if (seats[i] == 0) {
        int j = i + 1;
        while (j < seats.size() && seats[j] == 0)
          j++;
        int d = (j - i + 1) / 2;
        result = max(result, d);
        i = j;
      }
    }
    return result;
  }
};

int main() { return 0; }
