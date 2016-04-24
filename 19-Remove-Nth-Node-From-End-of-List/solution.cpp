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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode root(0);
        root.next = head;
        vector<ListNode *> stack(0);
        for (ListNode *p = &root; p; p = p->next)
            stack.push_back(p);
        ListNode *p = stack[stack.size() - n - 1];
        p->next = p->next->next;
        return root.next;
    }
};