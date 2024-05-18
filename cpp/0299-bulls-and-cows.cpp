class Solution {
public:
  string getHint(const string &secret, const string &guess) {
    string sec(secret.begin(), secret.end());
    string gue(guess.begin(), guess.end());
    sort(sec.begin(), sec.end());
    sort(gue.begin(), gue.end());
    string intersection;
    set_intersection(sec.begin(), sec.end(), gue.begin(), gue.end(),
                     back_inserter(intersection));
    int bull = 0;
    for (int i = 0; i < min(secret.size(), guess.size()); i++)
      if (secret[i] == guess[i])
        bull++;
    const int cow = intersection.size() - bull;
    return to_string(bull) + "A" + to_string(cow) + "B";
  }
};
