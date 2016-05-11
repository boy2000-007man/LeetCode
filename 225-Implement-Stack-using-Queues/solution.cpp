class Stack {
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        for (int i = q.size(); i; i--) {
            if (1 < i)
                q.push(q.front());
            q.pop();
        }
    }

    // Get the top element.
    int top() {
        int x;
        for (int i = q.size(); i; i--) {
            q.push(x = q.front());
            q.pop();
        }
        return x;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};