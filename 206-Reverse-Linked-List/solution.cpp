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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        else if (!head->next->next) {
            ListNode *p = head->next;
            p->next = head;
            head->next = NULL;
            return p;
        } else {
            ListNode *prev = head,
                     *curr = prev->next,
                     *next = curr->next;
            for (head->next = NULL; ; next = next->next) {
                curr->next = prev;
                if (!next)
                    return curr;
                prev = curr;
                curr = next;
            }
        }
    }
};