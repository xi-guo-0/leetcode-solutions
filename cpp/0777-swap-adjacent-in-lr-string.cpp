#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool canTransform(string start, string end) {
    if (start.size() != end.size())
      return false;

    int n = start.size(), start_idx = 0, end_idx = 0;
    while (start_idx < n || end_idx < n) {
      while (start_idx < n && start[start_idx] == 'X')
        start_idx++;
      while (end_idx < n && end[end_idx] == 'X')
        end_idx++;

      if ((start_idx == n) != (end_idx == n))
        return false;
      if (start_idx < n && end_idx < n) {
        if (start[start_idx] != end[end_idx])
          return false;
        if ((start[start_idx] == 'L' && start_idx < end_idx) ||
            (start[start_idx] == 'R' && start_idx > end_idx))
          return false;
        start_idx++;
        end_idx++;
      }
    }
    return true;
  }
};

int main() { return 0; }
