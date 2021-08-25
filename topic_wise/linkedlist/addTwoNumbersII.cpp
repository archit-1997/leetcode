/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : addTwoNumbersII.cpp
 * @created     : Wednesday Aug 25, 2021 14:19:21 IST
 */

#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* cur=head,*prev=NULL,*next=NULL;
        while(cur!=NULL){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //first we need to reverse both the linked list
        l1=reverse(l1);
        l2=reverse(l2);


        //now we just need to add these two linked list and keep on creating new nodes
        ListNode* head=new ListNode(0);
        ListNode* tmp=head;
        int carry=0,sum=0,a,b,val;
        while(l1!=NULL || l2!=NULL){
            a=0,b=0;
            if(l1){
                a=l1->val;
                l1=l1->next;
            }
            if(l2){
                b=l2->val;
                l2=l2->next;
            }
            
            sum=a+b+carry;
            val=sum%10;
            carry=sum/10;
            
            tmp->next=new ListNode(val);
            tmp=tmp->next;
        }
        if(carry!=0){
            tmp->next=new ListNode(carry);
            tmp=tmp->next;
        }
        tmp->next=NULL;
        ListNode* ans=head->next;
        ans=reverse(ans);
        return ans;


    }
};

