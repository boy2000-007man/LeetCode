/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    stack<pair<vector<NestedInteger>, int>> stk;
    void search() {
        while (!stk.empty())
            if (stk.top().second < stk.top().first.size())
                if (stk.top().first[stk.top().second].isInteger())
                    return ;
                else
                    stk.push(make_pair(stk.top().first[stk.top().second++].getList(), 0));
            else
                stk.pop();
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.push(make_pair(nestedList, 0));
    }

    int next() {
        search();
        return stk.top().first[stk.top().second++].getInteger();
    }

    bool hasNext() {
        search();
        return !stk.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */