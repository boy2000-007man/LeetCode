class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<bool> stk;
        stk.push(true);
        preorder += ',';
        for (int i = 0; 0 <= (i = preorder.find(',', i) - 1); i += 2)
            if (stk.empty())
                return false;
            else {
                if (stk.top())
                    stk.pop();
                else
                    stk.top() = true;
                if (preorder[i] != '#')
                    stk.push(false);
            }
        return stk.empty();
    }
};