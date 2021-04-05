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
    bool isPalindrome(ListNode* head) {
        
        stack<int> st;
        ListNode* rep=head;
        while(rep!=NULL){
            st.push(rep->val);
            rep=rep->next;
        }
        
        //now again traversing the linked list
        while(head!=NULL){
            if(head->val!=st.top())
                return false;
            st.pop();
            head=head->next;
        }
        
        return true;
        
    }
};