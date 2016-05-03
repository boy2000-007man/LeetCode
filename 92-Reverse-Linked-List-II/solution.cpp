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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode **p = &head;
        for (n -= m; --m; p = &((*p)->next));
        if (n) {
            ListNode *e = *p,
                     *t1 = e->next,
                     *t2 = e;
            for (ListNode *h = t1; n--; t1 = h) {
                h = h->next;
                t1->next = t2;
                t2 = t1;
            }
            *p = t2;
            e->next = t1;
        }
        return head;
    }
};