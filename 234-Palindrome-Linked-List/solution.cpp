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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head,
                 *fast = slow ? slow->next : slow;
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
            for (slow = head; fast; slow = slow->next, fast = fast->next)
                if (slow->val != fast->val)
                    return false;
        }
        return true;
    }
};