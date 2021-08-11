/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : palindromeLinkedList.cpp
 * @created     : Wednesday Aug 11, 2021 08:08:10 IST
 */

#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    
    ListNode* reverse(ListNode *head){
        if(head==NULL || head->next==NULL)
            return head;

        ListNode *cur=head,*next=NULL,*prev=NULL;

        while(cur!=NULL){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;

        //find the middle of the linked list
        ListNode* slow=head,*fast=head;
        while(slow && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //we need to reverse the second half of the linked list
        if(fast==NULL)
            slow=reverse(slow);
        else
            slow=reverse(slow->next);

        //keep one pointer on the start and then traverse start and slow
        ListNode* cur=head;
        while(slow!=NULL){
            if(cur->val != slow->val)
                return false;
            cur=cur->next;
            slow=slow->next;
        }

        return true;

    }
};
