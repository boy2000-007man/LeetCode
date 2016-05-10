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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = NULL;
        stack<pair<TreeNode **, pair<int, int>>> stk;
        if (!nums.empty())
            stk.push(make_pair(&root, make_pair(0, nums.size())));
        while (!stk.empty()) {
            int l = stk.top().second.first,
                r = stk.top().second.second,
                m = l + r >> 1;
            TreeNode *&p = *stk.top().first = new TreeNode(nums[m]);
            stk.pop();
            if (l < m)
                stk.push(make_pair(&p->left, make_pair(l, m)));
            if (m + 1 < r)
                stk.push(make_pair(&p->right, make_pair(m + 1, r)));
        }
        return root;
    }
};