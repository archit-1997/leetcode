/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @email       : architsingh456@gmail.com
 * @file        : swappingNodesInALinkedList.cpp
 * @created     : Sunday Jul 25, 2021 22:39:09 IST
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
  int countNodes(ListNode *head) {
    int ans = 0;
    while (head != NULL) {
      head = head->next;
      ans++;
    }
    return ans;
  }

  ListNode *swapNodes(ListNode *head, int k) {
    // count the number of nodes in the list
    ListNode *tmp = head;
    int n = countNodes(tmp);

    // find the kth node from the start
    ListNode *a = head, *b = head;
    int left = 1, right = 1;

    // kth node from the start
    while (left < k) {
      left++;
      a = a->next;
    }

    // kth node from end = (n-k+1)th node from the start
    while (right < (n - k + 1)) {
      right++;
      b = b->next;
    }

    // swap the values of nodes a and tmp
    int tmpVal = a->val;
    a->val = b->val;
    b->val = tmpVal;

    return head;
  }
};
