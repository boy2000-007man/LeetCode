/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1 = nullptr,
                 *h2 = nullptr,
                 **p1 = &h1;
        for (ListNode **p2 = &h2; head; head = head->next, *p2 = nullptr)
            if (head->val < x)
                p1 = &(*p1 = head)->next;
            else
                p2 = &(*p2 = head)->next;
        *p1 = h2;
        return h1;
    }
};