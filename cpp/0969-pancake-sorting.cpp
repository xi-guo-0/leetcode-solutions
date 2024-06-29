#include <vector>

using namespace std;

class Solution {
public:
  vector<int> pancakeSort(vector<int> &arr) {
    int n = arr.size();
    vector<int> res;
    for (int i = n; i > 1; --i) {
      int j = max_element(arr.begin(), arr.begin() + i) - arr.begin();
      if (j > 0) {
        reverse(arr.begin(), arr.begin() + j + 1);
        res.push_back(j + 1);
      }
      reverse(arr.begin(), arr.begin() + i);
      res.push_back(i);
    }
    return res;
  }
};

int main() { return 0; }
