#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> subdomainVisits(const vector<string> &cpdomains) {
    unordered_map<string, int> domainCountMap;

    for (const auto &domainEntry : cpdomains) {
      istringstream iss(domainEntry);
      int count;
      string domain;
      iss >> count >> domain;

      size_t pos = 0;
      while (pos != string::npos) {
        domainCountMap[domain] += count;
        pos = domain.find('.');
        if (pos != string::npos) {
          domain = domain.substr(pos + 1);
        }
      }
    }

    vector<string> result;
    for (const auto &[domain, count] : domainCountMap) {
      result.push_back(to_string(count) + " " + domain);
    }

    return result;
  }
};

int main() { return 0; }
