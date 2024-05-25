/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
  int getImportance(std::vector<Employee *> &employees, int id) {
    std::unordered_map<int, int> map;
    getId(employees, id, map);
    int sum = 0;
    for (const auto &[key, value] : map) {
      sum += value;
    }
    return sum;
  }

  void getId(const std::vector<Employee *> &employees, int id,
             std::unordered_map<int, int> &map) {
    if (map.find(id) == map.end()) {
      for (const auto *employee : employees) {
        if (id == employee->id) {
          map[id] = employee->importance;
          for (int subordinate : employee->subordinates) {
            getId(employees, subordinate, map);
          }
          break;
        }
      }
    }
  }
};
