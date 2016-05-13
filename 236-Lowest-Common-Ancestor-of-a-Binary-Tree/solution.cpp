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
    bool search(vector<TreeNode *> &route, TreeNode *root, TreeNode *p) {
        route.push_back(root);
        if (route.back() == p)
            return true;
        if (root->left && search(route, root->left, p))
            return true;
        if (root->right && search(route, root->right, p))
            return true;
        route.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> route[2];
        search(route[0], root, p);
        search(route[1], root, q);
        for (int i = 1; i < route[0].size() && i < route[1].size() && route[0][i] == route[1][i]; i++)
            root = route[0][i];
        return root;
    }
};