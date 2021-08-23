/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : linkedListCyleII.cpp
 * @created     : Monday Aug 23, 2021 06:54:28 IST
 */

#include <bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //if NULL or single node linked list
        if(head==NULL || head->next==NULL)
            return NULL;
        
        ListNode* slow=head,*fast=head;
        while(slow && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                //we have found a cycle
                ListNode* slow=head;
                while(1){
                    if(slow==fast)
                        return slow;
                    slow=slow->next;
                    fast=fast->next;
                }
            }
        }

        //if no cycle
        return NULL;

    }
};
