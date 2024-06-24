#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
  int minKBitFlips(vector<int> &nums, int k) {
    int n = nums.size();
    int flips = 0;
    deque<int> flipQueue;

    for (int i = 0; i < n; ++i) {

      if (!flipQueue.empty() && flipQueue.front() + k == i)
        flipQueue.pop_front();

      int currentBit = (nums[i] + flipQueue.size()) % 2;

      if (currentBit == 0) {

        if (i + k > n)
          return -1;

        flipQueue.push_back(i);
        flips++;
      }
    }

    return flips;
  }
};

int main() { return 0; }
