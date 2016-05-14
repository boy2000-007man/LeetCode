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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<pair<TreeNode *, bool>> stk;
        if (root)
            stk.push(make_pair(root, false));
        while (!stk.empty()) {
            TreeNode *r = stk.top().first;
            bool &v = stk.top().second;
            if (v) {
                stk.pop();
                result.push_back(r->val);
                if (r->right)
                    stk.push(make_pair(r->right, false));
            } else {
                v = !v;
                if (r->left)
                    stk.push(make_pair(r->left, false));
            }
        }
        return result;
    }
};