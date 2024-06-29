#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                           vector<vector<int>> &secondList) {
    return intervalIntersection(firstList.begin(), firstList.end(),
                                secondList.begin(), secondList.end());
  }

private:
  template <typename ForwardIt>
  vector<vector<int>> intervalIntersection(ForwardIt fa, ForwardIt la,
                                           ForwardIt fb, ForwardIt lb) {
    vector<vector<int>> result;
    while (fa != la && fb != lb) {
      if ((*fa)[0] == (*fb)[0]) {
        if ((*fa)[1] == (*fb)[1]) {
          result.push_back(vector<int>{(*fa)[0], (*fa)[1]});
          fa++;
          fb++;
        } else if ((*fa)[1] < (*fb)[1]) {
          result.push_back(vector<int>{(*fa)[0], (*fa)[1]});
          (*fb)[0] = (*fa)[1] + 1;
          fa++;
        } else {
          result.push_back(vector<int>{(*fb)[0], (*fb)[1]});
          (*fa)[0] = (*fb)[1] + 1;
          fb++;
        }
      } else if ((*fa)[0] < (*fb)[0]) {
        if ((*fb)[0] <= (*fa)[1]) {
          if ((*fa)[1] == (*fb)[1]) {
            result.push_back(vector<int>{(*fb)[0], (*fb)[1]});
            fa++;
            fb++;
          } else if ((*fa)[1] < (*fb)[1]) {
            result.push_back(vector<int>{(*fb)[0], (*fa)[1]});
            (*fb)[0] = (*fa)[1] + 1;
            fa++;
          } else {
            result.push_back(vector<int>{(*fb)[0], (*fb)[1]});
            (*fa)[0] = (*fb)[1] + 1;
            fb++;
          }
        } else {
          fa++;
        }
      } else {
        if ((*fa)[0] <= (*fb)[1]) {
          if ((*fa)[1] == (*fb)[1]) {
            result.push_back(vector<int>{(*fa)[0], (*fa)[1]});
            fa++;
            fb++;
          } else if ((*fa)[1] < (*fb)[1]) {
            result.push_back(vector<int>{(*fa)[0], (*fa)[1]});
            (*fb)[0] = (*fa)[1] + 1;
            fa++;
          } else {
            result.push_back(vector<int>{(*fa)[0], (*fb)[1]});
            (*fa)[0] = (*fb)[1] + 1;
            fb++;
          }
        } else {
          fb++;
        }
      }
    }
    return result;
  }
};

int main() { return 0; }
