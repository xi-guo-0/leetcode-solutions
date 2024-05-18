class Solution {
public:
    int ladderLength(const string& beginWord,
                     const string& endWord,
                     const vector<string>& dict) {
        const unordered_set<string> wordList(dict.begin(), dict.end());
        if (wordList.find(endWord) == wordList.end()) return 0;
        queue<string> current;
        queue<string> next;
        unordered_set<string> visited;
        
        int level = -1;
        
        auto state_is_valid = [&](const string& s) {
            return wordList.find(s) != wordList.end() || s == endWord;
        };
        auto state_is_target = [&](const string& s) {
            return s == endWord;
        };
        auto state_extend = [&](const string& s) {
            unordered_set<string> result;
            for (size_t i = 0; i < s.size(); i++) {
                string new_word(s);
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == new_word[i])
                        continue;
                    
                    swap(c, new_word[i]);
                    
                    if (state_is_valid(new_word) &&
                        visited.find(new_word) == visited.end()) {
                        result.insert(new_word);
                    }
                    
                    swap(c, new_word[i]);
                }
            }
            return result;
        };
        
        current.push(beginWord);
        visited.insert(beginWord);
        while (!current.empty()) {
            level++;
            while (!current.empty()) {
                const auto state = current.front();
                current.pop();
                
                if (state_is_target(state)) {
                    return level + 1;
                }
                
                const auto& new_states = state_extend(state);
                for (const auto& new_state : new_states) {
                    next.push(new_state);
                    visited.insert(new_state);
                }
            }
            swap(next, current);
        }
        return 0;
    }
};
