/**
 * @author      : archit 
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : swapNodesInPairs.cpp
 * @created     : Wednesday Jul 28, 2021 10:42:03 IST
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;

        ListNode* cur=head,*prev=NULL,*next=NULL,*ans=NULL;
        while(cur && cur->next){
            ListNode* tmp=cur;
            cur=cur->next;
            next=cur->next;
            //only if this is the first node
            if(ans==NULL)
                ans=cur;
            cur->next=tmp;
            if(prev==NULL)
                prev=cur->next;
            else{
                prev->next=cur;
                prev=cur->next;
            }
            cur=next;
        }
        if(next==NULL)
            prev->next=NULL;
        else 
            prev->next=next;
        return ans;
    }
};

