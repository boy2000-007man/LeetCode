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
    ListNode* reverseKGroup(ListNode* head, int k) {
        for (ListNode **ph = &head, *h = head, *p = h; h; ) {
            for (int i = 1; i < k && h; i++, h = h->next);
            if (h) {
                *ph = h;
                ListNode *t1 = p->next,
                         *t2 = p;
                p->next = h = h->next;
                ph = &p->next;
                p = t1;
                while (p != h) {
                    p = p->next;
                    t1->next = t2;
                    t2 = t1;
                    t1 = p;
                }
            }
        }
        return head;
    }
};