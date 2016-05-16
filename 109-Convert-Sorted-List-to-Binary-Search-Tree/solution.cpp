/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    void search(vector<TreeNode *> &tree, int l, int r) {
        int m = l + r >> 1;
        if (l < m) {
            tree[m]->left = tree[l + m >> 1];
            search(tree, l, m);
        }
        if (m + 1 < r) {
            tree[m]->right = tree[m + 1 + r >> 1];
            search(tree, m + 1, r);
        }
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<TreeNode *> tree;
        for ( ; head; head = head->next)
            tree.push_back(new TreeNode(head->val));
        search(tree, 0, tree.size());
        return tree.empty() ? NULL : tree[tree.size() >> 1];
    }
};