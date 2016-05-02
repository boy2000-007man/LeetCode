/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode dummy(0);
        for (TreeLinkNode *c = dummy.next = root; c && c->left; c = dummy.next)
            for (TreeLinkNode *n = &dummy; c; c = c->next) {
                n->next = c->left;
                n = n->next;
                n->next = c->right;
                n = n->next;
            }
    }
};