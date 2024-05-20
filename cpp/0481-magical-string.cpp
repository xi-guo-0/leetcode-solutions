#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int magicalString(int n) {
    if (n <= 0)
      return 0;

    string magic = "122";
    int i = 2;
    while (magic.size() < n) {
      if (magic[i] == '1') {
        if (magic.back() == '1')
          magic += '2';
        else
          magic += '1';
      } else {
        if (magic.back() == '1')
          magic += "22";
        else
          magic += "11";
      }
      i++;
    }

    int count = 0;
    for (int j = 0; j < n; j++) {
      if (magic[j] == '1')
        count++;
    }
    return count;
  }
};
