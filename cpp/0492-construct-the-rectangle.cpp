#include <cmath>
#include <vector>

class Solution {
public:
  std::vector<int> constructRectangle(int area) {
    int L;
    L = std::ceil(std::sqrt(area));
    while (area % L != 0) {
      L++;
    }
    std::vector<int> result(2);
    result[0] = L;
    result[1] = area / L;
    return result;
  }
};
