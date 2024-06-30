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
  vector<int> nextLargerNodes(ListNode *head) {
    stack<int> nodes;
    stack<int> sk;
    for (; head; head = head->next)
      nodes.push(head->val);
    vector<int> ans(nodes.size());
    int k = ans.size();
    while (!nodes.empty()) {
      while (!sk.empty() && sk.top() <= nodes.top())
        sk.pop();
      ans[--k] = sk.empty() ? 0 : sk.top();
      sk.push(nodes.top());
      nodes.pop();
    }
    return ans;
  }
};
