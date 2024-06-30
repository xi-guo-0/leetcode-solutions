#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<Token> sk;
    for (int i = 0; i < s.size();) {
      const Token tk = calPrefix(s, i);
      switch (tk) {
      case ABC: {
        i += 3;
        break;
      }
      case AB: {
        i += 2;
        sk.push(tk);
        break;
      }
      case A: {
        i += 1;
        sk.push(tk);
        break;
      }
      case BC: {
        i += 2;
        if (!sk.empty() && sk.top() == A)
          sk.pop();
        else
          return false;
        break;
      }
      case B: {
        i += 1;
        sk.push(tk);
        break;
      }
      case C: {
        i += 1;
        if (!sk.empty() && sk.top() == AB) {
          sk.pop();
        } else if (!sk.empty() && sk.top() == B) {
          sk.pop();
          if (!sk.empty() && sk.top() == A) {
            sk.pop();
          } else {
            return false;
          }
        } else {
          return false;
        }
        break;
      }
      default: {
        break;
      }
      }
    }
    return sk.empty();
  }

private:
  enum Token { ABC, AB, A, BC, B, C, OTHER };

  static Token calPrefix(const string &s, int i) {
    if (i < s.size()) {
      if (s[i] == 'a') {
        if (i + 1 < s.size() && s[i + 1] == 'b') {
          if (i + 2 < s.size() && s[i + 2] == 'c') {
            return ABC;
          } else {
            return AB;
          }
        } else {
          return A;
        }
      } else if (s[i] == 'b') {
        if (i + 1 < s.size() && s[i + 1] == 'c') {
          return BC;
        } else {
          return B;
        }
      } else if (s[i] == 'c') {
        return C;
      }
    }
    return OTHER;
  }
};

int main() { return 0; }
