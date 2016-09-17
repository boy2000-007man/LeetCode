/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *h;
    int l;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : h(head), l(0) {
        for (srand(time(nullptr)); head; head = head->next)
            l++;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *p = h;
        for (int i = rand() % l; i; i--)
            p = p->next;
        return p->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */