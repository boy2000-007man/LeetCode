class Solution {
    void calc(stack<int> &nums, char c) {
        int rval = nums.top();
        nums.pop();
        switch (c) {
            case '+':nums.top() += rval;break;
            case '-':nums.top() -= rval;break;
            case '*':nums.top() *= rval;break;
            case '/':nums.top() /= rval;break;
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (auto &s: tokens)
            if (s == "+" || s == "-" || s == "*" || s == "/")
                calc(nums, s[0]);
            else
                nums.push(atoi(s.c_str()));
        return nums.top();
    }
};