/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : reorderList.cpp
 * @created     : Saturday Aug 07, 2021 07:49:30 IST
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

    ListNode* reverse(ListNode* head){
        ListNode* cur=head,*next=NULL,*prev=NULL;
        while(cur!=NULL){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return;

        //find the middle  of the linked list
        ListNode* slow=head,*fast=head,*prev=NULL;
        while(slow && fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //break the list into two
        ListNode* second,*first=head;
        if(fast==NULL){
            //this is an even numbered list
            second=prev->next;
            prev->next=NULL;
        }else{
            //this is an odd numbered list
            second=slow->next;
            slow->next=NULL;
        }

        //reverse the second half
        second=reverse(second);

        ListNode *res=first;
        prev=NULL;
        while(second!=NULL){
             ListNode* tf=first;
             first=first->next;
             ListNode* ts=second;
             second=second->next;

             if(prev!=NULL)
                 prev->next=tf;
             tf->next=ts;
             prev=ts;
        }

        prev->next=first;
        if(second!=NULL)
            first->next=second;

    }
};
