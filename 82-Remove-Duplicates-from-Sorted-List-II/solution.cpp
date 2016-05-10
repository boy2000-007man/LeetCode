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
    ListNode* deleteDuplicates(ListNode* head) {
        for (ListNode **p = &head; *p && (*p)->next; )
            if ((*p)->val != (*p)->next->val)
                p = &(*p)->next;
            else {
                do {
                    *p = (*p)->next;
                } while ((*p)->next && (*p)->val == (*p)->next->val);
                *p = (*p)->next;
            }
        return head;
    }
};