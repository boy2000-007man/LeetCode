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
        for (dummy.next = root; root = dummy.next; ) {
            dummy.next = nullptr;
            for (TreeLinkNode *p = &dummy; root; root = root->next) {
                if (root->left)
                    p = p->next = root->left;
                if (root->right)
                    p = p->next = root->right;
            }
        }
    }
};