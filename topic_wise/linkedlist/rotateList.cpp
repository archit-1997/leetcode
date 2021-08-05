/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : rotateList.cpp
 * @created     : Thursday Aug 05, 2021 18:51:26 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int coutNodes(ListNode* head){
        int ans=0;
        while(head!=NULL){
            head=head->next;
            ans++;
        }
        return ans;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        //count the number of nodes in the linked list
        ListNode* tmp=head;
        int n=coutNodes(tmp);
        
        k%=n;
    
        //we need one pointer to the end of the linked list
        ListNode* second=head;
        while(second->next!=NULL)
            second=second->next;

        //now the distance for the second pointer will be n-k
        int dist=n-k;

        //now we need one pointer at dist position
        int count=1;
        ListNode* first=head;
        while(count<dist){
            count++;
            first=first->next;
        }


        second->next=head;
        head=first->next;
        first->next=NULL;

        return head;

    }
};

