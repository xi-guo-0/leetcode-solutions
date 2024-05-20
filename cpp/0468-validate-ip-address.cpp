#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string validIPAddress(string IP) {
    if (count(IP.begin(), IP.end(), '.') == 3) {
      vector<string> parts;
      size_t start = 0, end = 0;
      while ((end = IP.find('.', start)) != string::npos) {
        parts.push_back(IP.substr(start, end - start));
        start = end + 1;
      }
      parts.push_back(IP.substr(start));

      if (parts.size() != 4)
        return "Neither";

      for (const string &part : parts) {
        if (part.empty() || (part.size() > 1 && part[0] == '0') ||
            part.size() > 3)
          return "Neither";
        for (char c : part) {
          if (!isdigit(c))
            return "Neither";
        }
        int num = stoi(part);
        if (num < 0 || num > 255)
          return "Neither";
      }
      return "IPv4";
    }

    if (count(IP.begin(), IP.end(), ':') == 7) {
      vector<string> parts;
      size_t start = 0, end = 0;
      while ((end = IP.find(':', start)) != string::npos) {
        parts.push_back(IP.substr(start, end - start));
        start = end + 1;
      }
      parts.push_back(IP.substr(start));

      if (parts.size() != 8)
        return "Neither";

      for (const string &part : parts) {
        if (part.empty() || part.size() > 4)
          return "Neither";
        for (char c : part) {
          if (!isxdigit(c))
            return "Neither";
        }
      }
      return "IPv6";
    }

    return "Neither";
  }
};
