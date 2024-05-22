#include <algorithm>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
    vector<string> result;
    int minimum = numeric_limits<int>::max();

    for (int i = 0; i < list1.size(); ++i) {
      for (int j = 0; j < list2.size(); ++j) {
        if (list1[i] == list2[j]) {
          int sumIndex = i + j;
          if (sumIndex < minimum) {
            minimum = sumIndex;
            result.clear();
            result.push_back(list1[i]);
          } else if (sumIndex == minimum) {
            result.push_back(list1[i]);
          }
          break;
        }
      }
    }

    return result;
  }
};
