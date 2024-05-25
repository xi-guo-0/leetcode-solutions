class Solution {
public:
  vector<int> findRedundantConnection(const vector<vector<int>> &edges) {
    vector<int> s(edges.size() + 1);
    generate(s.begin(), s.end(), [n = 0]() mutable { return n++; });
    auto find = [&s](int i) {
      while (s[i] != i)
        i = s[i];
      return i;
    };
    for (const auto &e : edges) {
      const int a = find(e[0]);
      const int b = find(e[1]);
      if (a == b)
        return e;
      else
        s[b] = a;
    }
    return s;
  }
};
