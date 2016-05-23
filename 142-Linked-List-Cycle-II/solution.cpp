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
    ListNode *detectCycle(ListNode *head) {
        if (head && head->next) {
            ListNode *slow = head,
                     *fast = slow;
            do {
                slow = slow->next;
                fast = fast->next->next;
            } while (fast && fast->next && slow != fast);
            if (slow == fast) {
                int n = 0;
                do {
                    n++;
                    slow = slow->next;
                    fast = fast->next->next;
                } while (slow != fast);
                for ( ; ; head = head->next) {
                    slow = head;
                    for (int i = 0; i < n; i++)
                        slow = slow->next;
                    if (slow == head)
                        return head;
                }
            }
        }
        return nullptr;
    }
};