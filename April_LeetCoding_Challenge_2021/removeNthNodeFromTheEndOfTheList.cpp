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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        if (head == NULL)
            return head;

        ListNode *first = head, *second = head;

        int count = 1;
        while (count < n)
        {
            second = second->next;
            count++;
        }

        ListNode *prev = head;

        while (second->next != NULL)
        {
            prev = first;
            first = first->next;
            second = second->next;
        }

        if (first == head)
        {
            head = head->next;
        }
        else
        {
            prev->next = first->next;
        }

        return head;
    }
};