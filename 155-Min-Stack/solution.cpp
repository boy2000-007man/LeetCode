class MinStack {
    vector<int> stk;
    vector<pair<int, int>> min_ele;
public:
    /** initialize your data structure here. */
    MinStack() : stk(0), min_ele(0) {
    }
    
    void push(int x) {
        stk.push_back(x);
        if (min_ele.empty() || x < min_ele.back().second)
            min_ele.push_back(make_pair(stk.size() - 1, x));
    }
    
    void pop() {
        stk.pop_back();
        if (stk.size() <= min_ele.back().first)
            min_ele.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return min_ele.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */