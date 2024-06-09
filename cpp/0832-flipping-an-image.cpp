#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(const vector<vector<int>> &A) {
    vector<vector<int>> B(A);
    for (decltype(A.size()) i = 0; i != A.size(); ++i) {
      B[i].assign(A[i].crbegin(), A[i].crend());
    }
    for (auto &iv : B) {
      for (auto &i : iv)
        i = !i;
    }
    return B;
  }
};

int main() { return 0; }
