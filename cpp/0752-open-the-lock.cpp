#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
using State = array<uint8_t, 4>;

class Solution {
public:
  int openLock(const vector<string> &deadends, const string &target) {
    unordered_set<State, StateHash> deadendSet;
    transform(deadends.begin(), deadends.end(),
              inserter(deadendSet, deadendSet.end()), convert);
    return openLockHelper(deadendSet, convert(target));
  }

private:
  struct StateHash {
    size_t operator()(const State &state) const {
      size_t hash = 0;
      for (uint8_t num : state) {
        hash = hash * 31 + num;
      }
      return hash;
    }
  };

  int openLockHelper(unordered_set<State, StateHash> &deadends,
                     const State &target) {
    State initState = {0, 0, 0, 0};
    if (deadends.count(initState))
      return -1;

    unordered_set<State, StateHash> visited = {initState};
    queue<State> q;
    q.push(initState);
    int steps = 0;

    while (!q.empty()) {
      int qSize = q.size();
      for (int i = 0; i < qSize; ++i) {
        State cur = q.front();
        q.pop();

        if (cur == target)
          return steps;

        for (int j = 0; j < 4; ++j) {
          State nextStates[2] = {cur, cur};
          nextStates[0][j] = (nextStates[0][j] + 1) % 10;
          nextStates[1][j] = (nextStates[1][j] + 9) % 10;

          for (const State &nextState : nextStates) {
            if (!deadends.count(nextState) &&
                visited.insert(nextState).second) {
              q.push(nextState);
            }
          }
        }
      }
      ++steps;
    }
    return -1;
  }

  static State convert(const string &s) {
    State state;
    transform(s.begin(), s.end(), state.begin(),
              [](char c) { return c - '0'; });
    return state;
  }
};
