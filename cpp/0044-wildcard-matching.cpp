class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
    
    bool isMatch(const char *s, const char *p) {
        bool star = false;
        const char *str = s,
                   *ptr = p;
        for (; *str != '\0'; str++, ptr++) {
            switch(*ptr) {
                case '?':
                    break;
                case '*':
                    star = true;
                    s = str, p = ptr;
                    while (*p == '*') p++;
                    if (*p == '\0') return true;
                    str = s - 1;
                    ptr = p - 1;
                    break;
                default:
                    if (*str != *ptr) {
                        if (!star) return false;
                        s++;
                        str = s - 1;
                        ptr = p - 1;
                    }
            }
        }
        while (*ptr == '*') ptr++;
        return *ptr == '\0';
    }
};
