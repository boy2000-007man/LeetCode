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
    void recoverTree(TreeNode* root) {
        vector<pair<TreeNode *, TreeNode *>> result;
        stack<pair<TreeNode *, bool>> stk;
        stack<pair<TreeNode *, TreeNode *>> range;
        if (root) {
            stk.push(make_pair(root, false));
            range.push(make_pair(static_cast<TreeNode *>(NULL), static_cast<TreeNode *>(NULL)));
        }
        while (!stk.empty()) {
            TreeNode *p = stk.top().first,
                     *l = range.top().first,
                     *r = range.top().second;
            bool &v = stk.top().second;
            if (v) {
                stk.pop();
                range.pop();
                if (l && p->val < l->val)
                    result.push_back(make_pair(l, p));
                if (r && r->val < p->val)
                    result.push_back(make_pair(p, r));
                if (p->right) {
                    stk.push(make_pair(p->right, false));
                    range.push(make_pair(p, r));
                }
            } else {
                v = !v;
                if (p->left) {
                    stk.push(make_pair(p->left, false));
                    range.push(make_pair(l, p));
                }
            }
        }
        if (!result.empty())
            swap(result.front().first->val, result.back().second->val);
    }
};