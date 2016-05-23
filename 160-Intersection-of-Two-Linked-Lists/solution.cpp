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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0,
            lenB = 0;
        for (ListNode *p = headA; p; p = p->next)
            lenA++;
        for (ListNode *p = headB; p; p = p->next)
            lenB++;
        for ( ; lenB < lenA; lenA--)
            headA = headA->next;
        for ( ; lenA < lenB; lenB--)
            headB = headB->next;
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};