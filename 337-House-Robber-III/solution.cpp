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
    int rob(TreeNode* root) {
        stack<pair<TreeNode *, bool>> stk;
        if (root)
            stk.push(make_pair(root, false));
        while (!stk.empty()) {
            TreeNode *r = stk.top().first;
            bool &v = stk.top().second;
            if (v) {
                stk.pop();
                int child = 0;
                if (r->left) {
                    child += r->left->val;
                    if (r->left->left)
                        r->val += r->left->left->val;
                    if (r->left->right)
                        r->val += r->left->right->val;
                }
                if (r->right) {
                    child += r->right->val;
                    if (r->right->left)
                        r->val += r->right->left->val;
                    if (r->right->right)
                        r->val += r->right->right->val;
                }
                r->val = max(r->val, child);
            } else {
                v = !v;
                if (r->left)
                    stk.push(make_pair(r->left, false));
                if (r->right)
                    stk.push(make_pair(r->right, false));
            }
        }
        return root ? root->val : 0;
    }
};