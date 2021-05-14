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
    if (!l1 && !l2)
      return NULL;
    else if (!l1)
      return l2;
    else if (!l2)
      return l1;
    else {
      int v1 = 0, v2 = 0;
      string ans = "";
      int carry = 0;
      ListNode *head = new ListNode(0);
      ListNode *rep = head;
      while (l1 || l2) {
        int v1 = 0, v2 = 0;
        if (l1) {
          v1 = l1->val;
          l1 = l1->next;
        } else
          v1 = 0;
        if (l2) {
          v2 = l2->val;
          l2 = l2->next;
        } else
          v2 = 0;

        int sum = v1 + v2 + carry;
        rep->next = new ListNode(sum % 10);
        rep = rep->next;
        carry = sum / 10;
      }
      if (carry > 0) {
        rep->next = new ListNode(carry);
        rep = rep->next;
      }
      rep->next = NULL;
      return head->next;
    }
  }
};