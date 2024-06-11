#include <iostream>
#include <ranges>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    int n = position.size();
    if (n == 0)
      return 0;

    vector<pair<int, double>> cars;
    for (int i = 0; i < n; ++i) {
      cars.emplace_back(position[i], (double)(target - position[i]) / speed[i]);
    }
    sort(cars.begin(), cars.end(), greater<pair<int, double>>());

    int fleets = 1;
    double currTime = cars[0].second;
    for (int i = 1; i < n; ++i) {
      if (cars[i].second > currTime) {
        ++fleets;
        currTime = cars[i].second;
      }
    }

    return fleets;
  }
};

int main() { return 0; }
