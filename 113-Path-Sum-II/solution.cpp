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
    void search(vector<vector<int>> &result, vector<int> &path, TreeNode *root, int sum) {
        path.push_back(root->val);
        sum -= root->val;
        if (root->left || root->right) {
            if (root->left)
                search(result, path, root->left, sum);
            if (root->right)
                search(result, path, root->right, sum);
        } else if (!sum)
            result.push_back(path);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        if (root)
            search(result, path, root, sum);
        return result;
    }
};