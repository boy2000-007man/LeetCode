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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = NULL;
        for (ListNode **p = &l3; l1 || l2; p = &(*p)->next) {
            int t = (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            *p = new ListNode(t % 10);
            if (t /= 10)
                if (l1)
                    l1->val += t;
                else
                    l1 = new ListNode(t);
        }
        return l3;
    }
};