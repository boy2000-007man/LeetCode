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
public:
    int countNodes(TreeNode* root, int l = 0, int r = 0) {
        if (!l)
            for (TreeNode *p = root; p; p = p->left)
                l++;
        if (!r)
            for (TreeNode *p = root; p; p = p->right)
                r++;
        if (l == r)
            return (1 << l) - 1;
        int cnt = countNodes(root->left, l - 1, 0) + 1;
        if (cnt >> l - 1)
            return cnt + countNodes(root->right, 0, r - 1);
        else
            return cnt + (1 << r - 1) - 1;
    }
};