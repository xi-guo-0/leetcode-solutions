#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int uniqueMorseRepresentations(vector<string> &words) {
    const vector<string> morse_code = {
        ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
        ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
        "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};
    unordered_set<string> unique_transformations;

    for (const auto &word : words) {
      string morse_word;
      for (char c : word) {
        morse_word += morse_code[c - 'a'];
      }
      unique_transformations.insert(morse_word);
    }

    return unique_transformations.size();
  }
};

int main() { return 0; }
