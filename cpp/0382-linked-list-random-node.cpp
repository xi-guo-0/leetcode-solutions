#include <random>
#include <vector>

using namespace std;

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
  Solution(ListNode *head) {
    while (head) {
      d.push_back(head->val);
      head = head->next;
    }
  }

  int getRandom() {
    uniform_int_distribution<int> dist(0, d.size() - 1);
    return d[dist(rng)];
  }

private:
  vector<int> d;
  mt19937 rng{random_device{}()};
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
