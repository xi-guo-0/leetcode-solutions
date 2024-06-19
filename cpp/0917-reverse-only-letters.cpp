#include <string>

using namespace std;

class Solution {
public:
  string reverseOnlyLetters(string S) {
    if (S.size() == 0) {
      return S;
    }
    for (int i = 0, j = S.size() - 1; i < j; i++, j--) {
      while (i < j && !isalpha(S[i]))
        i++;
      while (i < j && !isalpha(S[j]))
        j--;
      swap(S[i], S[j]);
    }
    return S;
  }
};

int main() { return 0; }
