class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    long num = long(numerator);
    long den = long(denominator);
    string res;
    if (num * den < 0) {
      res += "-";
    }
    num = abs(num);
    den = abs(den);
    res += to_string(num / den);
    num %= den;
    if (num == 0) {
      return res;
    }

    res += ".";
    int loop_ind = -1;
    unordered_map<long, long> m;
    while (num != 0) {
      if (m.count(num)) {
        loop_ind = m[num];
        break;
      } else {
        m[num] = res.size();
      }
      num *= 10;
      res += to_string(num / den);
      num %= den;
    }
    if (num == 0) {
      return res;
    }
    return res.substr(0, loop_ind) + "(" + res.substr(loop_ind) + ")";
  }
};
