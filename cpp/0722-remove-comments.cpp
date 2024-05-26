#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> removeComments(vector<string> &source) {
    vector<string> result;
    bool inBlockComment = false;
    string newLine = "";

    for (const string &line : source) {
      int i = 0;
      if (!inBlockComment) {
        newLine.clear();
      }

      while (i < line.size()) {
        if (!inBlockComment && i + 1 < line.size() && line[i] == '/' &&
            line[i + 1] == '*') {
          inBlockComment = true;
          i += 2;
        } else if (inBlockComment && i + 1 < line.size() && line[i] == '*' &&
                   line[i + 1] == '/') {
          inBlockComment = false;
          i += 2;
        } else if (!inBlockComment && i + 1 < line.size() && line[i] == '/' &&
                   line[i + 1] == '/') {
          break;
        } else if (!inBlockComment) {
          newLine += line[i++];
        } else {
          i++;
        }
      }

      if (!inBlockComment && !newLine.empty()) {
        result.push_back(newLine);
      }
    }

    return result;
  }
};

int main() { return 0; }
