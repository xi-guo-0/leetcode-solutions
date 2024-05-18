#include<unordered_map>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_map<int, bool> used;
        for (auto i : nums) used[i] = false;
    
        for (auto i : nums) {
            if (used[i]) continue;
            
            int length = 1;
            
            used[i] = true;
            
            for (int j = i + 1; used.find(j) != used.end(); ++j) {
                used[j] = true;
                ++length;
            }
            for (int j = i - 1; used.find(j) != used.end(); --j) {
                used[j] = true;
                ++length;
            }
            longest = max(longest, length);
        }
        return longest;
    }
};
