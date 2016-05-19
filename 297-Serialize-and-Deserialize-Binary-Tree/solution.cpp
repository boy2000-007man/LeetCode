/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        for (vector<TreeNode *> stk(1, root); !stk.empty(); ) {
            TreeNode *p = stk.back();
            stk.pop_back();
            if (p) {
                ss << p->val << " ";
                stk.push_back(p->right);
                stk.push_back(p->left);
            } else
                ss << "# ";
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = nullptr;
        vector<TreeNode **> stk(1, &root);
        stringstream ss(data);
        for (string s; ss >> s; )
            if (s == "#") {
                *stk.back() = nullptr;
                stk.pop_back();
            } else {
                TreeNode *p = *stk.back() = new TreeNode(atoi(s.c_str()));
                stk.pop_back();
                stk.push_back(&p->right);
                stk.push_back(&p->left);
            }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));