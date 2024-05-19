class Solution {
public:
  vector<double> calcEquation(const vector<vector<string>> &equations,
                              const vector<double> &values,
                              const vector<vector<string>> &queries) {
    constructGraph(equations, values);
    floyd();
    vector<double> result;
    for (const auto &query : queries) {
      const auto &a = query[0];
      const auto &b = query[1];
      if (!vertex.count(a) || !vertex.count(b) || !grid[a].count(b))
        result.push_back(-1.0);
      else
        result.push_back(grid[a][b]);
    }
    return result;
    ;
  }

private:
  set<string> vertex;
  map<const string, map<const string, double>> grid;

  void constructGraph(const vector<vector<string>> &equations,
                      const vector<double> &values) {
    for (int i = 0; i < equations.size(); i++) {
      const string &a = equations[i][0];
      const string &b = equations[i][1];
      const double val = values[i];
      vertex.insert(a);
      vertex.insert(b);
      if (!grid.count(a))
        grid[a] = map<const string, double>();
      if (!grid.count(b))
        grid[b] = map<const string, double>();
      if (!grid[a].count(b))
        grid[a][b] = val;
      if (!grid[b].count(a))
        grid[b][a] = 1.0 / val;
      grid[a][a] = 1.0;
      grid[b][b] = 1.0;
    }
  }

  void floyd() {
    for (auto k = vertex.begin(); k != vertex.end(); k++) {
      for (auto i = vertex.begin(); i != vertex.end(); i++) {
        for (auto j = vertex.begin(); j != vertex.end(); j++) {
          if (!grid[*i].count(*j) && grid[*i].count(*k) && grid[*k].count(*j))
            grid[*i][*j] = grid[*i][*k] * grid[*k][*j];
        }
      }
    }
  }
};
