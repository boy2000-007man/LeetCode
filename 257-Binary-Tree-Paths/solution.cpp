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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result(0);
        stack<pair<TreeNode *, string>> stk;
        if (root)
            stk.push(make_pair(root, ""));
        while (!stk.empty()) {
            TreeNode *r = stk.top().first;
            stringstream ss;
            ss << stk.top().second << r->val;
            stk.pop();
            if (!r->left && !r->right)
                result.push_back(ss.str());
            else {
                ss << "->";
                if (r->right)
                    stk.push(make_pair(r->right, ss.str()));
                if (r->left)
                    stk.push(make_pair(r->left, ss.str()));
            }
        }
        return result;
    }
};