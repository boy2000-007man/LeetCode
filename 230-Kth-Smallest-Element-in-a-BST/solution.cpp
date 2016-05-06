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
    int search(TreeNode *root, int k, int &val) {
        if (k <= 0)
            return 0;
        int num = 0;
        if (root->left)
            num += search(root->left, k, val);
        if (++num == k)
            val = root->val;
        if (root->right)
            num += search(root->right, k - num, val);
        return num;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int val;
        search(root, k, val);
        return val;
    }
};