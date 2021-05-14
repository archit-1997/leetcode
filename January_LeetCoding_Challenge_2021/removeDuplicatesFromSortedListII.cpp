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
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == NULL || head->next == NULL)
      return head;
    ListNode *rep = new ListNode(0);
    ListNode *prev = rep;
    rep->next = head;
    while (head != NULL) {
      while (head->next && head->val == head->next->val)
        head = head->next;
      if (prev->next == head)
        prev = prev->next;
      else
        prev->next = head->next;
      head = head->next;
    }
    return rep->next;
  }
};