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
    bool isValidBST(TreeNode* root) {
        if (root) {
            list<pair<int *, int *>> bound(1, make_pair((int *)(NULL), (int *)(NULL)));
            for (list<TreeNode *> queue(1, root); !queue.empty(); queue.pop_front()) {
                TreeNode *p = queue.front();
                int *l = bound.front().first,
                    *m = &p->val,
                    *r = bound.front().second;
                bound.pop_front();
                if ((l && *m <= *l) || (r && *r <= *m))
                    return false;
                else {
                    if (p->left) {
                        queue.push_back(p->left);
                        bound.push_back(make_pair(l, m));
                    }
                    if (p->right) {
                        queue.push_back(p->right);
                        bound.push_back(make_pair(m, r));
                    }
                }
            }
        }
        return true;
    }
};