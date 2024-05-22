#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

struct Fraction {
  int num, denom;
  Fraction(int n, int d) : num(n), denom(d) {
    int g = gcd(abs(num), abs(denom));
    num /= g;
    denom /= g;
    if (denom < 0) {
      num *= -1;
      denom *= -1;
    }
  }
  Fraction operator+(const Fraction &f) const {
    return Fraction(num * f.denom + f.num * denom, denom * f.denom);
  }
  Fraction operator-(const Fraction &f) const {
    return Fraction(num * f.denom - f.num * denom, denom * f.denom);
  }
  string toString() const { return to_string(num) + "/" + to_string(denom); }
};

Fraction parseFraction(istream &is) {
  int n, d;
  char s;
  is >> n >> s >> d;
  return Fraction(n, d);
}

class Solution {
public:
  string fractionAddition(string exp) {
    stringstream ss(exp);
    Fraction res = parseFraction(ss);
    char op;
    while (ss >> op) {
      Fraction frac = parseFraction(ss);
      res = (op == '+') ? res + frac : res - frac;
    }
    return res.toString();
  }
};
