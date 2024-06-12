#include <cmath>
#include <iostream>
#include <string>

using namespace std;

bool is_prime(int num) {
  if (num <= 1)
    return false;
  if (num <= 3)
    return true;
  if (num % 2 == 0 || num % 3 == 0)
    return false;
  for (int i = 5; i * i <= num; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0)
      return false;
  }
  return true;
}

bool is_palindrome(int num) {
  string str = to_string(num);
  int left = 0, right = str.length() - 1;
  while (left < right) {
    if (str[left] != str[right])
      return false;
    left++;
    right--;
  }
  return true;
}

class Solution {
public:
  int primePalindrome(int n) {
    if (n <= 2)
      return 2;
    if (n <= 3)
      return 3;
    if (n <= 5)
      return 5;
    if (n <= 7)
      return 7;
    if (n <= 11)
      return 11;

    for (int length = 1; length < 6; ++length) {
      for (int root = pow(10, length - 1); root < pow(10, length); ++root) {
        string s = to_string(root);
        string rev_s(s.rbegin(), s.rend());
        int y = stoi(s + rev_s.substr(1));
        if (y >= n && is_prime(y))
          return y;
        y = stoi(s + rev_s);
        if (y >= n && is_prime(y))
          return y;
      }
    }
    return -1;
  }
};

int main() { return 0; }
