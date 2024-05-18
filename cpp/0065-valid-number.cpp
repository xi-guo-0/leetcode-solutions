class Solution {
public:
    bool isNumber(string str) {
        const char *s = str.c_str();
        char* endptr;
        strtod(s, &endptr);
        
        if (endptr == s)
            return false;
        for (; *endptr; endptr++)
            if (!isspace(*endptr))
                return false;
        return true;
    }
};
