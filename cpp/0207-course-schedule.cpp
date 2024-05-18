class Solution {
public:
  bool canFinish(const int numCourses,
                 const vector<vector<int>> &prerequisites) {
    unordered_map<int, int> course2indegree;
    unordered_multimap<int, int> links;
    for (int i = 0; i < numCourses; ++i)
      course2indegree[i] = 0;
    for (const auto &p : prerequisites) {
      links.insert({p[0], p[1]});
      ++course2indegree[p[1]];
    }
    while (true) {
      bool has_choice = false;
      int index = 0;
      for (const auto &c : course2indegree) {
        if (c.second == 0) {
          index = c.first;
          has_choice = true;
          break;
        }
      }
      if (!has_choice)
        break;
      auto range = links.equal_range(index);
      for (auto it = range.first; it != range.second; ++it) {
        --course2indegree[it->second];
      }
      links.erase(index);
      course2indegree.erase(index);
    }
    bool ans = true;
    for (const auto &c : course2indegree) {
      if (c.second != 0) {
        ans = false;
        break;
      }
    }
    return ans;
  }
};
