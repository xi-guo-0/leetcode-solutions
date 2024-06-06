/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
  int numComponents(ListNode *head, vector<int> &nums) {
    unordered_set<int> g(nums.begin(), nums.end());
    int ans = 0, dp = 0;
    for (; head; head = head->next)
      if (g.count(head->val))
        ++dp;
      else
        dp ? ++ans : 0, dp = 0;
    if (dp)
      ++ans;
    return ans;
  }
};
