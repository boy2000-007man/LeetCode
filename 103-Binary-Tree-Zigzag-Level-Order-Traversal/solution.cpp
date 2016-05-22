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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        for (int num = 0; !q.empty(); q.pop()) {
            if (--num <= 0) {
                num = q.size();
                result.push_back({});
            }
            TreeNode *r = q.front();
            result.back().push_back(r->val);
            if (r->left)
                q.push(r->left);
            if (r->right)
                q.push(r->right);
        }
        for (int i = 1; i < result.size(); i += 2)
            reverse(begin(result[i]), end(result[i]));
        return result;
    }
};