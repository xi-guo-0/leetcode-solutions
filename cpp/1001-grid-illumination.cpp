#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> gridIllumination(int n, vector<vector<int>> &lamps,
                               vector<vector<int>> &queries) {

    unordered_map<int, int> row;
    unordered_map<int, int> col;
    unordered_map<int, int> diag;
    unordered_map<int, int> anti_diag;

    unordered_set<int64_t> lamp_positions;

    auto get_key = [](int x, int y) -> int64_t {
      return (static_cast<int64_t>(x) << 32) | y;
    };

    for (const auto &lamp : lamps) {
      int x = lamp[0], y = lamp[1];
      int64_t key = get_key(x, y);
      if (lamp_positions.insert(key).second) {
        row[x]++;
        col[y]++;
        diag[x - y]++;
        anti_diag[x + y]++;
      }
    }

    vector<int> result;
    result.reserve(queries.size());
    vector<vector<int>> directions = {{0, 0},  {0, 1},  {0, -1},
                                      {1, 0},  {-1, 0}, {1, 1},
                                      {1, -1}, {-1, 1}, {-1, -1}};

    for (const auto &query : queries) {
      int x = query[0], y = query[1];

      if (row[x] > 0 || col[y] > 0 || diag[x - y] > 0 || anti_diag[x + y] > 0) {
        result.push_back(1);
      } else {
        result.push_back(0);
      }

      for (const auto &dir : directions) {
        int nx = x + dir[0], ny = y + dir[1];
        int64_t key = get_key(nx, ny);
        if (lamp_positions.erase(key)) {
          row[nx]--;
          col[ny]--;
          diag[nx - ny]--;
          anti_diag[nx + ny]--;
        }
      }
    }

    return result;
  }
};

int main() { return 0; }
