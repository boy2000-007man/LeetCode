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
    int sumNumbers(TreeNode* root, int number = 0) {
        if (!root)
            return 0;
        else {
            number = 10 * number + root->val;
            if (!root->left && !root->right)
                return number;
            else
                return sumNumbers(root->left, number) + sumNumbers(root->right, number);
        }
    }
};