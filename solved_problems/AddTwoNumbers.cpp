/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *head=NULL,*prev=NULL;
        
        int carry=0;
        
        while(l1||l2)
        {
            int v1=l1?l1->val:0;
            int v2=l2?l2->val:0;
            
            int sum=v1+v2+carry;
            
            carry=sum/10;
            int val=sum%10;
            
            ListNode *cur=new ListNode(val);
            if(!head)
                head=cur;
            //tabhi jab pehli baar na kr re ho tb
            if(prev)
                prev->next=cur;
            prev=cur;
            l1=l1?l1->next:NULL;
            l2=l2?l2->next:NULL;
        }
        
        if(carry>0)
        {
            ListNode *l=new ListNode(carry);
            prev->next=l;
        }
        
        return head;
        
    }
};
