#include <cctype>
#include <iostream>
#include <string>

using namespace std;

string maskEmail(const string &email) {
  int at_index = email.find('@');
  string masked;
  masked += email[0];
  masked += "*****";
  masked += email[at_index - 1];
  masked += email.substr(at_index);
  transform(masked.begin(), masked.end(), masked.begin(),
            [](unsigned char c) { return std::tolower(c); });
  return masked;
}

string maskPhoneNumber(const string &phone) {
  string digits;
  for (char c : phone) {
    if (isdigit(c)) {
      digits += c;
    }
  }
  int localLength = digits.length() - 10;
  string masked;
  if (localLength == 0) {
    masked = "***-***-" + digits.substr(digits.length() - 4);
  } else {
    masked = "+";
    for (int i = 0; i < localLength; ++i) {
      masked += "*";
    }
    masked += "-***-***-" + digits.substr(digits.length() - 4);
  }
  return masked;
}
class Solution {
public:
  string maskPII(string s) {
    if (s.find('@') != string::npos) {
      return maskEmail(s);
    } else {
      return maskPhoneNumber(s);
    }
  }
};
