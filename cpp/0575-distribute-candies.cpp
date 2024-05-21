#include <unordered_set>
#include <vector>

class Solution {
public:
  int distributeCandies(std::vector<int> &candies) {
    std::unordered_set<int> set;
    for (int num : candies) {
      set.insert(num);
    }
    int maximum = candies.size() / 2;
    return set.size() < maximum ? set.size() : maximum;
  }
};
