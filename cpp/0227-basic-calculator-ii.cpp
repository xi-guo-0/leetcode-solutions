class Solution {
public:
  int calculate(const string &s) {
    for (int i = 0; i < s.size(); i++) {
      while (i < s.size() && s[i] == ' ')
        i++;
      if (s.size() <= i)
        break;
      else if (isdigit(s[i])) {
        int j = i + 1;
        while (j < s.size() && isdigit(s[j]))
          j++;
        num.push(stoll(s.substr(i, j - i)));
        i = j - 1;
      } else if (op.empty() || s[i] == '(' ||
                 priority[op.top()] < priority[s[i]]) {
        op.push(s[i]);
      } else if (s[i] == ')') {
        while (op.top() != '(')
          calc();
        op.pop();
      } else {
        while (!op.empty() && priority[s[i]] <= priority[op.top()])
          calc();
        op.push(s[i]);
      }
    }
    while (!op.empty())
      calc();
    return num.top();
  }

private:
  unordered_map<char, int> priority{
      {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 3}};
  stack<long long> num;
  stack<char> op;
  void calc() {
    const long long b = num.top();
    num.pop();
    switch (op.top()) {
    case '+':
      num.top() += b;
      break;
    case '-':
      num.top() -= b;
      break;
    case '*':
      num.top() *= b;
      break;
    case '/':
      num.top() /= b;
      break;
    }
    op.pop();
  }
};
