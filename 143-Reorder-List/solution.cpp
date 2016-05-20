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
    void reorderList(ListNode* head) {
        ListNode *slow = head,
                 *fast = slow;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (slow && (fast = slow->next)) {
            ListNode *p = fast->next;
            slow->next = fast->next = nullptr;
            for (ListNode *t; t = p; fast = t) {
                p = p->next;
                t->next = fast;
            }
            while (fast) {
                p = head->next;
                head->next = fast;
                fast = fast->next;
                head = head->next->next = p;
            }
        }
    }
};