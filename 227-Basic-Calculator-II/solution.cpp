class Solution {
    int priority(char op) {
        switch (op) {
            case '+':case '-':return 0;
            case '*':case '/':return 1;
        }
        return -1;
    }
    void calc(stack<int> &nums, stack<char> &ops) {
        int b = nums.top();
        nums.pop();
        switch (ops.top()) {
            case '+':nums.top() += b;break;
            case '-':nums.top() -= b;break;
            case '*':nums.top() *= b;break;
            case '/':nums.top() /= b;break;
        }
        ops.pop();
    }
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        for (int i = 0; s[i]; i++)
            switch (s[i]) {
                case ' ':break;
                case '0':case '1':case '2':case '3':
                case '4':case '5':case '6':case '7':
                case '8':case '9':
                    for (nums.push(s[i] - '0'); '0' <= s[i + 1] && s[i + 1] <= '9'; i++)
                        nums.top() = 10 * nums.top() + (s[i + 1] - '0');
                    break;
                case '+':case '-':case '*':case '/':
                    while (!ops.empty() && priority(s[i]) <= priority(ops.top()))
                        calc(nums, ops);
                    ops.push(s[i]);
            }
        while (!ops.empty())
            calc(nums, ops);
        return nums.top();
    }
};