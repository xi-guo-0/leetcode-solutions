class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        if (haystack.size() < needle.size())
            return -1;
        
        const int N = haystack.size() - needle.size() + 1;
        for (int i = 0; i < N; i++) {
            int j = i;
            int k = 0;
            while (k < needle.size() && haystack[j] == needle[k]) {
                j++;
                k++;
            }
            if (k == needle.size())
                return i;
        }
        return -1;
    }
};
