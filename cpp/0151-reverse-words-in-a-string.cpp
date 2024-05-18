class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        stack<string> sk;
        ostringstream os;
        while (is >> s)
            sk.push(s);
        if (!sk.empty()) {
            os << sk.top();
            sk.pop();
        }
        while (!sk.empty()) {
            os << " " << sk.top();
            sk.pop();
        }
        return os.str();
    }
};
