/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  int count_nodes(ListNode *head) {
    ListNode *rep = head;
    int ans = 0;
    while (rep != NULL) {
      ans++;
      rep = rep->next;
    }
    return ans;
  }

  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int nA = count_nodes(headA), nB = count_nodes(headB);

    if (nA > nB) {
      int d = nA - nB;
      int c = 1;
      while (c <= d) {
        c++;
        headA = headA->next;
      }
      // now both the nodes are at the same position
      while (headA != NULL) {
        if (headA == headB)
          return headA;
        headA = headA->next;
        headB = headB->next;
      }
      // now intersection has been found
      return NULL;

    } else if (nB > nA) {
      int d = nB - nA;
      int c = 1;
      while (c <= d) {
        c++;
        headB = headB->next;
      }
      // now both the nodes are at the same position
      while (headA != NULL) {
        if (headA == headB)
          return headA;
        headA = headA->next;
        headB = headB->next;
      }
      // now intersection has been found
      return NULL;
    } else {
      while (headA != NULL) {
        if (headA == headB)
          return headA;
        headA = headA->next;
        headB = headB->next;
      }
      return NULL;
    }
  }
};