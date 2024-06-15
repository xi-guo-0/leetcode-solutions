#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    vector<vector<int>> result;
    result.push_back(std::move(vector<int>{r0, c0}));

    auto insert = [&result, &R, &C](int r, int c) {
      if (0 <= r && r < R && 0 <= c && c < C)
        result.push_back(std::move(vector<int>{r, c}));
    };

    int len = 1;
    bool rightdown = true;
    while (result.size() != R * C) {
      if (rightdown) {
        for (int j = 0; j < len; j++) {
          c0++;
          insert(r0, c0);
        }
        for (int i = 0; i < len; i++) {
          r0++;
          insert(r0, c0);
        }
      } else {
        for (int j = 0; j < len; j++) {
          c0--;
          insert(r0, c0);
        }
        for (int i = 0; i < len; i++) {
          r0--;
          insert(r0, c0);
        }
      }
      rightdown = !rightdown;
      len++;
    }
    return result;
  }
};

int main() { return 0; }
