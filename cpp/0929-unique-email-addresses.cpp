#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int numUniqueEmails(vector<string> &emails) {
    unordered_set<string> unique_emails;
    for (auto &email : emails) {
      auto pivot = email.find_first_of('@');
      auto local = email.substr(0, pivot);
      auto domain = email.substr(pivot);
      local.erase(remove(local.begin(), local.end(), '.'), local.end());
      auto pos = local.find_first_of('+');
      unique_emails.insert((pos != string::npos) ? local.erase(pos) + domain
                                                 : local + domain);
    }
    return static_cast<int>(unique_emails.size());
  }
};

int main() { return 0; }
