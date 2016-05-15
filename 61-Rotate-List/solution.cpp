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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head) {
            vector<ListNode *> vec;
            for (ListNode *p = head; p; p = p->next)
                vec.push_back(p);
            if (k %= vec.size()) {
                head = vec[vec.size() - k];
                vec.back()->next = vec[0];
                vec[vec.size() - k - 1]->next = NULL;
            }
        }
        return head;
    }
};