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
    ListNode* swapPairs(ListNode* head) {
        ListNode **p = &head;
        for (ListNode *e = *p; e && e->next; e = *p) {
            *p = e->next;
            e->next = (*p)->next;
            (*p)->next = e;
            p = &e->next;
        }
        return head;
    }
};