/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;̦
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head;
    if (l1 == NULL && l2 == NULL) {
      head = NULL;
      return head;
    } else if (l1 == NULL)
      return l2;
    else if (l2 == NULL)
      return l1;
    // we need to find out which list has the smaller starting point

    if (l1->val < l2->val) {
      head = l1;
      l1 = l1->next;
    } else {
      head = l2;
      l2 = l2->next;
    }
    ListNode *ans = head;
    // now head is pointing to the smaller linked. list
    while (l1 != NULL || l2 != NULL) {
      if (l1 && l2) {
        if (l1->val <= l2->val) {
          head->next = l1;
          l1 = l1->next;
        } else {
          head->next = l2;
          l2 = l2->next;
        }
      } else if (l1) {
        head->next = l1;
        l1 = l1->next;
      } else {
        head->next = l2;
        l2 = l2->next;
      }
      head = head->next;
    }

    return ans;
  }
};