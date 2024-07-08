#include <vector>

using namespace std;

class Solution {
public:
  vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2) {
    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());
    while (arr1.size() < arr2.size())
      arr1.push_back(0);
    while (arr2.size() < arr1.size())
      arr2.push_back(0);
    int carry = 0;
    vector<int> ans(arr1.size());
    for (int i = 0; i < arr1.size(); ++i) {
      const int sum = arr1[i] + arr2[i] + carry;
      switch (sum) {
      case -1:
        ans[i] = 1, carry = 1;
        break;
      case 0:
        ans[i] = 0, carry = 0;
        break;
      case 1:
        ans[i] = 1, carry = 0;
        break;
      case 2:
        ans[i] = 0, carry = -1;
        break;
      case 3:
        ans[i] = 1, carry = -1;
        break;
      }
    }
    while (carry != 0) {
      if (carry == -1) {
        ans.push_back(1);
        carry = 1;
      } else {
        ans.push_back(1);
        carry = 0;
      }
    }
    while (1 < ans.size() && ans.back() == 0)
      ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() { return 0; }
