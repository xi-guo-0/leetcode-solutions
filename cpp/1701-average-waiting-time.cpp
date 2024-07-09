#include <vector>
using namespace std;

class Solution {
public:
  double averageWaitingTime(vector<vector<int>> &customers) {
    long long totalWaitingTime = 0;
    int currentTime = 0;

    for (auto &customer : customers) {
      int arrival = customer[0];
      int timeToCook = customer[1];

      currentTime = max(currentTime, arrival) + timeToCook;

      totalWaitingTime += currentTime - arrival;
    }

    return static_cast<double>(totalWaitingTime) / customers.size();
  }
};