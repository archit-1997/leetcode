/*Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.*/

class Solution {
public:
ListNode* swapPairs(ListNode* head) {

    if (!head || !head->next) {
        return head;
    }
   
    auto result = head->next;
    
    auto it = head;        
    ListNode* prev = nullptr;
    while(it && it->next) {                                
		if (prev) prev->next = it->next;					
		prev = it;			
		auto n = it->next;
        prev->next = n->next;
        n->next = prev;                      		    
		it = prev->next;            			
    }
   
   return result;
}
};
