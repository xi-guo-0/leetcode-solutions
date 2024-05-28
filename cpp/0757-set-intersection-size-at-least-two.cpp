#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int intersectionSizeTwo(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b) {
           return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
         });

    int count = 0;
    int largest = -1;
    int second_largest = -1;

    for (const auto &interval : intervals) {
      if (interval[0] > largest) {
        count += 2;
        largest = interval[1];
        second_largest = largest - 1;
      } else if (interval[0] > second_largest) {
        count += 1;
        second_largest = largest;
        largest = interval[1];
      }
    }

    return count;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> intervals = {{1, 3}, {1, 4}, {2, 5}, {3, 5}};
  cout << sol.intersectionSizeTwo(intervals) << endl;
  return 0;
}
