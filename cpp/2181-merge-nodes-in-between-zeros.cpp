struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
  ListNode *mergeNodes(ListNode *head) {
    auto dummy = head;
    while (head != nullptr && head->next != nullptr) {
      auto val = head->next->val;
      if (head->next->val != 0) {
        head->val += val;
        head->next = head->next->next;
      } else {
        head->next = head->next->next;
        head = head->next;
      }
    }
    return dummy;
  }
};

int main() { return 0; }
