/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : intersectionOfTwoLinkedLists.cpp
 * @created     : Friday Aug 13, 2021 10:08:46 IST
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

    int countNodes(ListNode* head){
        if(head==NULL)
            return 0;
        return 1+countNodes(head->next);
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //count the number of nodes in both the lists
        ListNode* t1=headA,*t2=headB;
        int n1=countNodes(t1),n2=countNodes(t2);

        //find the difference between the lengths
        int diff=abs(n1-n2);

        int count=0;
        if(n1>n2){
            while(count<diff){
                headA=headA->next;
                count++;
            }
        }
        else{
            while(count<diff){
                headB=headB->next;
                count++;
            }
        }

        while(headA!=NULL){
            if(headA==headB)
                return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};
