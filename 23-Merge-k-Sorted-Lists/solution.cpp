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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        while (1 < lists.size()) {
            for (int i = 0; i < lists.size() >> 1; i++) {
                ListNode dummy(0);
                dummy.next = lists[i];
                for (ListNode *p1 = &dummy, *p2 = lists[i + (lists.size() + 1 >> 1)]; p2; )
                    if (!p1->next) {
                        p1->next = p2;
                        p2 = NULL;
                    } else if (p2->val <= p1->next->val) {
                        ListNode *t = p1->next;
                        p1->next = p2;
                        do {
                            p1 = p1->next;
                        } while (p1->next && p1->next->val <= t->val);
                        p2 = p1->next;
                        p1->next = t;
                    } else
                        p1 = p1->next;
                lists[i] = dummy.next;
            }
            lists.resize(lists.size() + 1 >> 1);
        }
        if (lists.empty())
            return NULL;
        else
            return lists[0];
    }
};