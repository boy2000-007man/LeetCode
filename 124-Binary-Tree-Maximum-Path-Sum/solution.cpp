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
    pair<int, int> search(TreeNode *root) {
        if (!root)
            return {INT_MIN, 0};
        else {
            auto l = search(root->left),
                 r = search(root->right);
            return {max(max(l.first, r.first), max(0, l.second) + root->val + max(0, r.second)), max(0, max(l.second, r.second)) + root->val};
        }
    }
public:
    int maxPathSum(TreeNode* root) {
        return search(root).first;
    }
};