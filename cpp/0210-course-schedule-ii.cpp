class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    unordered_map<int, int> course2indegree;
    unordered_multimap<int, int> links;
    vector<int> ans;
    for (int i = 0; i < numCourses; ++i)
      course2indegree[i] = 0;
    for (const auto &p : prerequisites) {
      links.insert({p[1], p[0]});
      ++course2indegree[p[0]];
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
      ans.push_back(index);
      auto range = links.equal_range(index);
      for (auto it = range.first; it != range.second; ++it) {
        --course2indegree[it->second];
      }
      links.erase(index);
      course2indegree.erase(index);
    }
    bool can_finish = true;
    for (const auto &c : course2indegree) {
      if (c.second != 0) {
        can_finish = false;
        break;
      }
    }
    return can_finish ? ans : vector<int>();
  }
};
