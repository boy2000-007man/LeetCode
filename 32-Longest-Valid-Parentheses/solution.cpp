class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        stack<int> lens;
        lens.push(0);
        stack<char> stk;
        for (char c: s)
            if (c == '(') {
                stk.push(c);
                lens.push(0);
            } else if (!stk.empty()) {
                stk.pop();
                int len = lens.top() + 2;
                lens.pop();
                lens.top() += len;
            } else {
                max_len = max(max_len, lens.top());
                lens.top() = 0;
            }
        for ( ; !lens.empty(); lens.pop())
            max_len = max(max_len, lens.top());
        return max_len;
    }
};