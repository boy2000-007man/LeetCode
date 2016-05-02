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
    bool hasPathSum(TreeNode* root, int sum) {
        stack<pair<TreeNode *, int>> stk;
        if (root)
            stk.push(make_pair(root, 0));
        while (!stk.empty()) {
            TreeNode *r = stk.top().first;
            int s = r->val + stk.top().second;
            stk.pop();
            if (r->left || r->right) {
                if (r->left)
                    stk.push(make_pair(r->left, s));
                if (r->right)
                    stk.push(make_pair(r->right, s));
            } else if (s == sum)
                return true;
        }
        return false;
    }
};