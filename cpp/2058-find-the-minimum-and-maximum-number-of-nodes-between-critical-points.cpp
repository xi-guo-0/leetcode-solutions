#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
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
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    vector<int> criticalPoints;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    int index = 0;

    while (curr != nullptr && curr->next != nullptr) {
      ListNode *next = curr->next;
      if (prev != nullptr &&
          ((curr->val > prev->val && curr->val > next->val) ||
           (curr->val < prev->val && curr->val < next->val))) {
        criticalPoints.push_back(index);
      }
      prev = curr;
      curr = next;
      ++index;
    }

    if (criticalPoints.size() < 2) {
      return {-1, -1};
    }

    int minDistance = numeric_limits<int>::max();
    int maxDistance = criticalPoints.back() - criticalPoints.front();

    for (size_t i = 1; i < criticalPoints.size(); ++i) {
      minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
    }

    return {minDistance, maxDistance};
  }
};

int main() { return 0; }