#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> exclusiveTime(const int n, const vector<string> &logs) {
    stack<int> s;
    vector<int> ans(n, 0);
    int prev = 0, timestamp = 0;
    size_t idPos = logs.front().find(':');
    int id = stoi(logs.front().substr(0, idPos));
    prev = stoi(logs.front().substr(idPos + 7));
    s.push(id);

    for (size_t i = 1; i < logs.size(); i++) {
      size_t colonPos = logs[i].find(':');
      id = stoi(logs[i].substr(0, colonPos));
      if (logs[i][colonPos + 1] == 's') {
        timestamp = stoi(logs[i].substr(colonPos + 7));
        if (!s.empty())
          ans[s.top()] += timestamp - prev;
        s.push(id);
        prev = timestamp;
      } else {
        timestamp = stoi(logs[i].substr(colonPos + 5));
        ans[s.top()] += timestamp - prev + 1;
        s.pop();
        prev = timestamp + 1;
      }
    }
    return ans;
  }
};
