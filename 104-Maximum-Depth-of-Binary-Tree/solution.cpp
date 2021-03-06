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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        for (int num = 0; !q.empty(); q.pop()) {
            if (--num <= 0) {
                num = q.size();
                depth++;
            }
            TreeNode *r = q.front();
            if (r->left)
                q.push(r->left);
            if (r->right)
                q.push(r->right);
        }
        return depth;
    }
};