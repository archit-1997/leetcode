/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *rep=head;
        if(head==NULL || head->next==NULL)
            return head;
        
        while(rep!=NULL){
            ListNode* tmp=rep;
            while(tmp->next!=NULL && tmp->val==tmp->next->val)
                tmp=tmp->next;
            tmp=tmp->next;
            rep->next=tmp;
            rep=rep->next;
        }
        return head;
    }
};