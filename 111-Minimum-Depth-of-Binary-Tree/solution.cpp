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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        list<TreeNode *> queue(1, root);
        int depth = 1, end = queue.size();
        for (TreeNode *p; !queue.empty(); queue.pop_front()) {
            p = queue.front();
            if (!p->left || !p->right)
                break;
            queue.push_back(p->left);
            queue.push_back(p->right);
            if (!(--end)) {
                depth++;
                end = queue.size() - 1;
            }
        }
        return depth;
    }
};