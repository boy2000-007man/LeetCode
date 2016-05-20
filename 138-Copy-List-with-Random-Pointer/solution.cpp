/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> um;
        for (RandomListNode **p1 = &head, *p2 = head; p2; p1 = &(*p1)->next, p2 = p2->next) {
            um[p2] = *p1 = new RandomListNode(p2->label);
            (*p1)->random = p2->random;
        }
        for (RandomListNode *p = head; p; p = p->next)
            if (p->random)
                p->random = um[p->random];
        return head;
    }
};