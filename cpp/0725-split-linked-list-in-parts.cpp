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

#include <vector>

using namespace std;

class Solution {
public:
  vector<ListNode *> splitListToParts(ListNode *root, int k) {
    vector<ListNode *> ans;
    ListNode *cur = root;
    int const len = lenOfList(cur);
    int const width = len / k;
    int rem = len % k;
    for (int i = 0; i < k; ++i) {
      ans.push_back(cur);
      for (int j = 1; j < width + (i < rem); ++j) {
        if (cur) {
          cur = cur->next;
        }
      }
      if (cur) {
        ListNode *prev = cur;
        cur = cur->next;
        prev->next = nullptr;
      }
    }
    return ans;
  }

private:
  int lenOfList(ListNode *root) {
    int ans = 0;
    while (root) {
      ++ans;
      root = root->next;
    }
    return ans;
  }
};

int main() { return 0; }
