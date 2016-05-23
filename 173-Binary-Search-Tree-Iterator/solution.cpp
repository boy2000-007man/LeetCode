/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<pair<TreeNode *, bool>> stk;
public:
    BSTIterator(TreeNode *root) {
        if (root)
            stk.push({root, false});
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        while (!stk.top().second++)
            if (stk.top().first->left)
                stk.push({stk.top().first->left, false});
        TreeNode *r = stk.top().first;
        stk.pop();
        if (r->right)
            stk.push({r->right, false});
        return r->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */