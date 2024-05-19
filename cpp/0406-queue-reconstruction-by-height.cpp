class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
      return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    });
    list<vector<int>> reconstruct;
    for (auto &p : people)
      reconstruct.insert(next(reconstruct.begin(), p[1]), move(p));
    return vector<vector<int>>(reconstruct.begin(), reconstruct.end());
  }
};
