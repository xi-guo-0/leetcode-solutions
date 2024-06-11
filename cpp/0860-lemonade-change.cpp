#include <vector>

using namespace std;

class Solution {
public:
  bool lemonadeChange(const vector<int> &bills) {
    int five = 0, ten = 0, twenty = 0;
    for (const int bill : bills) {
      if (bill == 5) {
        five++;
      } else if (bill == 10) {
        if (0 < five) {
          five--;
          ten++;
        } else {
          return false;
        }
      } else {
        if (0 < ten && 0 < five) {
          twenty++;
          ten--;
          five--;
        } else if (2 < five) {
          twenty++;
          five -= 3;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};

int main() { return 0; }
