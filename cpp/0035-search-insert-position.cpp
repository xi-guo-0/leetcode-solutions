class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return distance(nums.begin(),
                        lower_bound(nums.begin(),
                                    nums.end(),
                                    target));
    }
    
    template<typename ForwardIterator, typename T>
    ForwardIterator lower_bound(ForwardIterator first,
                                ForwardIterator last,
                                T value) {
        while (first != last) {
            auto mid = next(first, distance(first, last) / 2);
            if (value > *mid) first = next(mid);
            else              last = mid;
        }
        return first;
    }
};
