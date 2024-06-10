#include <cstddef>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Master {
public:
  int guess(string word);
};

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
  void findSecretWord(vector<string> &words, Master &master) {
    random_device rd;
    mt19937 gen(rd());

    for (;;) {
      string candidate = generateCandidate(words, gen);
      int matches = master.guess(candidate);
      if (matches == 6)
        return;
      filterWords(words, candidate, matches);
    }
  }

private:
  string generateCandidate(const vector<string> &words, mt19937 &gen) {

    vector<pair<string, int>> similarityScores;
    for (const string &word : words) {
      int score = calculateSimilarityScore(words, word);
      similarityScores.emplace_back(word, score);
    }

    sort(similarityScores.begin(), similarityScores.end(),
         [](const pair<string, int> &a, const pair<string, int> &b) {
           return a.second > b.second;
         });

    return similarityScores[0].first;
  }

  int calculateSimilarityScore(const vector<string> &words,
                               const string &word) {
    int score = 0;
    for (const string &w : words) {
      score += matchCount(word, w);
    }
    return score;
  }

  void filterWords(vector<string> &words, const string &candidate,
                   int matches) {
    vector<string> filteredList;
    for (const string &word : words) {
      if (matchCount(candidate, word) == matches) {
        filteredList.push_back(word);
      }
    }
    words = std::move(filteredList);
  }

  int matchCount(const string &a, const string &b) {
    int matches = 0;
    for (size_t i = 0; i < a.size(); ++i) {
      if (a[i] == b[i])
        ++matches;
    }
    return matches;
  }
};

int main() { return 0; }
