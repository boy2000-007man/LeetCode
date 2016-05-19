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
    ListNode* sortList(ListNode* head) {
        if (head && head->next) {
            ListNode *slow = head,
                     *fast = slow->next;
            while (fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }
            fast = sortList(slow->next);
            slow->next = nullptr;
            slow = sortList(head);
            for (ListNode **p = &head; slow || fast; *(p = &(*p)->next) = nullptr)
                if (slow && (!fast || slow->val < fast->val)) {
                    *p = slow;
                    slow = slow->next;
                } else {
                    *p = fast;
                    fast = fast->next;
                }
        }
        return head;
    }
};