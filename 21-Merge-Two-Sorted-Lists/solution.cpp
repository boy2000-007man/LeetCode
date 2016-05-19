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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        for (ListNode **p = &head; l1 || l2; *(p = &(*p)->next) = nullptr)
            if (l1 && (!l2 || l1->val < l2->val))
                l1 = (*p = l1)->next;
            else
                l2 = (*p = l2)->next;
        return head;
    }
};