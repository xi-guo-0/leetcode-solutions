class Solution {
public:
  int findCircleNum(const vector<vector<int>> &M) {
    if (M.size() == 0 || M[0].size() == 0) {
      return 0;
    }
    int n = M.size();
    vector<int> v(n, 0);
    generate(v.begin(), v.end(), [i = 0]() mutable { return i++; });
    auto find = [&v](int i) {
      while (i != v[i])
        i = v[i];
      return i;
    };
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (M[i][j])
          v[find(i)] = find(j);
    set<int> s;
    for (const int i : v)
      s.insert(find(i));
    return s.size();
  }
};
