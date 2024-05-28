#include <algorithm>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> tokenize(const string &text) {
  const regex ws_re("([\\(\\)])|([^\\(\\)\\s]+)");
  const vector<int> submatches{0};
  vector<string> result;
  copy(sregex_token_iterator(text.begin(), text.end(), ws_re, submatches),
       sregex_token_iterator(), back_inserter(result));
  return result;
}

void substituteVariables(vector<string> &tokens,
                         const unordered_map<string, int> &evalMap) {
  for (auto &token : tokens) {
    if (evalMap.find(token) != evalMap.end()) {
      token = to_string(evalMap.at(token));
    }
  }
}

map<string, int> applyOperation(const map<string, int> &left,
                                const map<string, int> &right, char op) {
  map<string, int> result;
  if (op == '+') {
    result = left;
    for (const auto &[key, value] : right) {
      result[key] += value;
    }
  } else if (op == '-') {
    result = left;
    for (const auto &[key, value] : right) {
      result[key] -= value;
    }
  } else if (op == '*') {
    for (const auto &[leftKey, leftValue] : left) {
      for (const auto &[rightKey, rightValue] : right) {
        string newKey = leftKey.empty()    ? rightKey
                        : rightKey.empty() ? leftKey
                                           : leftKey + "*" + rightKey;
        vector<string> sortedVars;
        stringstream ss(newKey);
        string var;
        while (getline(ss, var, '*')) {
          sortedVars.push_back(var);
        }
        sort(sortedVars.begin(), sortedVars.end());
        string sortedKey = sortedVars.empty() ? "" : sortedVars[0];
        for (size_t i = 1; i < sortedVars.size(); ++i) {
          sortedKey += "*" + sortedVars[i];
        }
        result[sortedKey] += leftValue * rightValue;
      }
    }
  }
  return result;
}

map<string, int> evaluate(const vector<string> &tokens) {
  stack<map<string, int>> operands;
  stack<char> operators;

  auto applyTopOperation = [&]() {
    char op = operators.top();
    operators.pop();
    auto right = operands.top();
    operands.pop();
    auto left = operands.top();
    operands.pop();
    operands.push(applyOperation(left, right, op));
  };

  for (const auto &token : tokens) {
    if (token == "+" || token == "-") {
      while (!operators.empty() && operators.top() != '(') {
        applyTopOperation();
      }
      operators.push(token[0]);
    } else if (token == "*") {
      while (!operators.empty() && operators.top() == '*') {
        applyTopOperation();
      }
      operators.push(token[0]);
    } else if (token == "(") {
      operators.push('(');
    } else if (token == ")") {
      while (operators.top() != '(') {
        applyTopOperation();
      }
      operators.pop();
    } else {
      map<string, int> term;
      if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
        term[""] = stoi(token);
      } else {
        term[token] = 1;
      }
      operands.push(term);
    }
  }

  while (!operators.empty()) {
    applyTopOperation();
  }

  return operands.top();
}

vector<string> formatResult(const map<string, int> &result) {
  vector<pair<string, int>> formattedPairs;
  for (const auto &[term, coefficient] : result) {
    if (coefficient != 0) {
      formattedPairs.emplace_back(term, coefficient);
    }
  }

  sort(formattedPairs.begin(), formattedPairs.end(),
       [](const auto &a, const auto &b) {
         int degreeA = count(a.first.begin(), a.first.end(), '*') +
                       (a.first.empty() ? 0 : 1);
         int degreeB = count(b.first.begin(), b.first.end(), '*') +
                       (b.first.empty() ? 0 : 1);
         if (degreeA != degreeB) {
           return degreeA > degreeB;
         }
         return a.first < b.first;
       });

  vector<string> formatted;
  for (const auto &[term, coefficient] : formattedPairs) {
    if (term.empty()) {
      formatted.push_back(to_string(coefficient));
    } else {
      formatted.push_back(to_string(coefficient) + "*" + term);
    }
  }

  return formatted;
}

class Solution {
public:
  vector<string> basicCalculatorIV(string expression, vector<string> &evalvars,
                                   vector<int> &evalints) {
    unordered_map<string, int> evalMap;
    for (size_t i = 0; i < evalvars.size(); ++i) {
      evalMap[evalvars[i]] = evalints[i];
    }

    vector<string> tokens = tokenize(expression);
    substituteVariables(tokens, evalMap);
    map<string, int> result = evaluate(tokens);
    return formatResult(result);
  }
};

int main() { return 0; }
