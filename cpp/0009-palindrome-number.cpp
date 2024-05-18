class Solution {
public:
    bool isPalindrome(const int x) {
        if (x < 0) {return false;}
        else if (x == 0) {return true;}
        string s(to_string(x));
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
};
