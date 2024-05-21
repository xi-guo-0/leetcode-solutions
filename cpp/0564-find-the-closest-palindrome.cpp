#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string nearestPalindromic(string n) {
    if (n.length() == 1)
      return to_string(stoi(n) - 1);

    int digits = n.length();
    vector<long> candidates{static_cast<long>(pow(10, digits - 1)) - 1,
                            static_cast<long>(pow(10, digits)) + 1};

    int mid = (digits + 1) / 2;
    long prefix = stol(n.substr(0, mid));
    vector<long> v{prefix, prefix + 1, prefix - 1};
    for (long i : v) {
      string postfix = to_string(i);
      if (digits % 2 != 0)
        postfix.pop_back();
      reverse(postfix.begin(), postfix.end());
      candidates.push_back(stol(to_string(i) + postfix));
    }

    long result = LONG_MAX, num = stol(n), mindiff = LONG_MAX;
    for (long candidate : candidates) {
      if (candidate != num && abs(candidate - num) < mindiff) {
        mindiff = abs(candidate - num);
        result = candidate;
      } else if (abs(candidate - num) == mindiff)
        result = min(result, candidate);
    }

    return to_string(result);
  }
};
