#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int subarrayBitwiseORs(vector<int> &arr) {
    unordered_set<int> all, current, next;
    for (int num : arr) {
      next.clear();
      next.insert(num);
      for (int x : current) {
        next.insert(x | num);
      }
      current.swap(next);
      for (int x : current) {
        all.insert(x);
      }
    }
    return all.size();
  }
};

int main() { return 0; }
