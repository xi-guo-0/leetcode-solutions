#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  static bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
  }

  vector<int> survivedRobotsHealths(vector<int> &pos, vector<int> &healths,
                                    string directions) {
    int n = pos.size();
    vector<pair<int, int>> robots;
    for (int i = 0; i < n; ++i) {
      robots.push_back({pos[i], i});
    }
    sort(robots.begin(), robots.end(), comp);

    stack<int> stack;
    vector<int> survivors;

    for (const auto &robot : robots) {
      int index = robot.second;
      if (directions[index] == 'L') {
        while (!stack.empty() && healths[stack.top()] < healths[index]) {
          stack.pop();
          healths[index]--;
        }
        if (stack.empty()) {
          survivors.push_back(index);
        } else if (healths[stack.top()] == healths[index]) {
          stack.pop();
        } else {
          healths[stack.top()]--;
          if (healths[stack.top()] == 0)
            stack.pop();
        }
      } else {
        stack.push(index);
      }
    }

    while (!stack.empty()) {
      survivors.push_back(stack.top());
      stack.pop();
    }

    sort(survivors.begin(), survivors.end());

    vector<int> result;
    for (int index : survivors) {
      result.push_back(healths[index]);
    }
    return result;
  }
};

int main() { return 0; }
