#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int scheduleCourse(vector<vector<int>> &courses) {
    sort(
        courses.begin(), courses.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

    priority_queue<int> pq;
    int time = 0;

    for (auto &course : courses) {
      int duration = course[0];
      int endDay = course[1];

      if (time + duration <= endDay) {
        pq.push(duration);
        time += duration;
      } else if (!pq.empty() && pq.top() > duration) {
        time += duration - pq.top();
        pq.pop();
        pq.push(duration);
      }
    }

    return pq.size();
  }
};
