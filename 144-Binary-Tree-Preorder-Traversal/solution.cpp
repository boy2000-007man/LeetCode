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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> stk;
        if (root)
            stk.push(root);
        while (!stk.empty()) {
            TreeNode *r = stk.top();
            stk.pop();
            result.push_back(r->val);
            if (r->right)
                stk.push(r->right);
            if (r->left)
                stk.push(r->left);
        }
        return result;
    }
};