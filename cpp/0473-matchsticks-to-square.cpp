class Solution {
public:
  bool makesquare(vector<int> &n) {
    if (n.size() < 4)
      return false;
    int s = 0;
    for (const int v : n)
      s += v;
    if (s % 4 != 0)
      return false;
    sort(n.begin(), n.end(), [](const int &l, const int &r) { return l > r; });
    vector<int> sides(4, 0);
    return dfs(sides, n, 0, s / 4);
  }

private:
  bool dfs(vector<int> &s, const vector<int> &m, int i, const int t) {
    if (i == m.size())
      return s[0] == s[1] && s[1] == s[2] && s[2] == s[3];
    for (int j = 0; j < 4; ++j) {
      if (s[j] + m[i] > t)
        continue;
      int k = j;
      while (--k >= 0)
        if (s[j] == s[k])
          break;
      if (k != -1)
        continue;
      s[j] += m[i];
      if (dfs(s, m, i + 1, t))
        return true;
      s[j] -= m[i];
    }
    return false;
  }
};
