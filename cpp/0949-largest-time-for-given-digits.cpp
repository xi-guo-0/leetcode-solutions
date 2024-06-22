#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string largestTimeFromDigits(vector<int> &arr) {
    int sum = -1;
    int res_hour = 0;
    int res_minute = 0;
    sort(arr.begin(), arr.end());
    do {
      const int hour = arr[0] * 10 + arr[1];
      const int minute = arr[2] * 10 + arr[3];
      if (0 <= hour && hour < 24 && 0 <= minute && minute < 60) {
        if (sum < hour * 60 + minute) {
          sum = hour * 60 + minute;
          res_hour = hour;
          res_minute = minute;
        }
      }
    } while (next_permutation(arr.begin(), arr.end()));
    if (sum != -1) {
      ostringstream os;
      if (res_hour < 10)
        os << "0";
      os << to_string(res_hour) << ":";
      if (res_minute < 10)
        os << "0";
      os << to_string(res_minute);
      return os.str();
    }
    return "";
  }
};

int main() { return 0; }
