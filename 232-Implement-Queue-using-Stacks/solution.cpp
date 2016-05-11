class Queue {
    stack<int> stk;
public:
    // Push element x to the back of queue.
    void push(int x) {
        stk.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> tmp;
        while (!stk.empty()) {
            if (1 < stk.size())
                tmp.push(stk.top());
            stk.pop();
        }
        while (!tmp.empty()) {
            stk.push(tmp.top());
            tmp.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        stack<int> tmp(stk);
        while (1 < tmp.size())
            tmp.pop();
        return tmp.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk.empty();
    }
};