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
    void deleteNode(ListNode* node) {
        if (node)
            for ( ; node->next; node->next->next ? node = node->next : node->next = nullptr)
                node->val = node->next->val;
    }
};