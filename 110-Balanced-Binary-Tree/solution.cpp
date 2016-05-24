/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int search(TreeNode *p) {
        if (!p)
            return 0;
        else {
            int l, r;
            if ((l = search(p->left)) < 0 || (r = search(p->right)) < 0 || 1 < abs(l - r))
                return -1;
            else
                return max(l, r) + 1;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        return 0 <= search(root);
    }
};