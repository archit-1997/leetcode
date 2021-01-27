/*Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *cur=head,*prev=head;
        
        while(n-- >0)
            cur=cur->next;
        
        if(cur==NULL)
            return head->next;//pehla node deleted
        else
        {
            while(cur->next!=NULL)
            {
                cur=cur->next;
                prev=prev->next;
            }
        }
        
        prev->next=prev->next->next;
        
        return head;
        
    }
};
