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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    return str2List(addStrings(List2str(l1), List2str(l2)));
  }

private:
  string addStrings(const string &num1, const string &num2) {
    if (num1.size() == 0 || num1 == "0") {
      return num2;
    } else if (num2.size() == 0 || num2 == "0") {
      return num1;
    }
    const int m = num1.size();
    const int n = num2.size();
    int k = max(m, n);
    int c = 0;
    string s(1 + k, '0');
    for (int i = m - 1, j = n - 1; 0 <= i || 0 <= j; i--, j--, k--) {
      const int a = 0 <= i ? num1[i] - '0' : 0;
      const int b = 0 <= j ? num2[j] - '0' : 0;
      s[k] += (a + b + c) % 10;
      c = (a + b + c) / 10;
    }
    s[k] += c;
    return s[0] == '0' ? s.substr(s.find_first_not_of('0')) : s;
  }

  string List2str(ListNode *l) {
    if (!l)
      return "0";
    ostringstream os;
    for (; l; l = l->next)
      os << static_cast<char>(l->val + '0');
    return os.str();
  }

  ListNode *str2List(const string &s) {
    ListNode dummy(-1);
    ListNode *p = &dummy;
    for (const auto ch : s) {
      p->next = new ListNode(ch - '0');
      p = p->next;
    }
    return dummy.next;
  }
};
