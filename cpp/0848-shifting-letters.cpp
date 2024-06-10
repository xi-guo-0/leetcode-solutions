#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string shiftingLetters(string S, const vector<int> &shifts) {
    vector<int> shift_sum(shifts);
    partial_sum(shifts.rbegin(), shifts.rend(), shift_sum.rbegin(),
                [](const int a, const int b) { return (a + b) % 26; });
    for (int i = 0; i < shift_sum.size(); ++i)
      S[i] = ((S[i] - 'a' + shift_sum[i]) % 26) + 'a';
    return S;
  }
};

int main() { return 0; }
