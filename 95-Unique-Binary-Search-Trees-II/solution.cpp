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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> tree[n + 2][n + 1];
        for (int i = 1; i < n + 2; i++)
            tree[i][i - 1].push_back(NULL);
        for (int i = 1; i <= n; i++)
            for (int j = i; 1 <= j; j--)
                for (int k = j; k <= i; k++)
                    for (auto left: tree[j][k - 1])
                        for (auto right: tree[k + 1][i]) {
                            TreeNode *r = new TreeNode(k);
                            r->left = left;
                            r->right = right;
                            tree[j][i].push_back(r);
                        }
        return n ? tree[1][n] : tree[0][0];
    }
};