class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        for (auto& p : intervals)
            insert(res, p);
        return res;
    }
    
private:
    void insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto it = intervals.begin();
        while (it != intervals.end()) {
            if (newInterval[1] < (*it)[0]) {
                intervals.insert(it, newInterval);
                return;
            } else if ((*it)[1] < newInterval[0]) {
                it++;
                continue;
            } else {
                newInterval[0] = min(newInterval[0], (*it)[0]);
                newInterval[1] = max(newInterval[1], (*it)[1]);
                it = intervals.erase(it);
            }
        }
        intervals.push_back(newInterval);
        return;
    }
};
