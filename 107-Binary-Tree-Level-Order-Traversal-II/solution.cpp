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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<vector<int>> stk;
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        for (int level_num = 0; !q.empty(); q.pop()) {
            if (--level_num <= 0) {
                level_num = q.size();
                stk.push(vector<int>(0));
            }
            TreeNode *r = q.front();
            stk.top().push_back(r->val);
            if (r->left)
                q.push(r->left);
            if (r->right)
                q.push(r->right);
        }
        vector<vector<int>> result;
        for (; !stk.empty(); stk.pop())
            result.push_back(stk.top());
        return result;
    }
};