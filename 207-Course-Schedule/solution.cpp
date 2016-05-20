class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> next(numCourses);
        vector<int> prev(numCourses);
        for (auto &p: prerequisites) {
            next[p.second].push_back(p.first);
            prev[p.first]++;
        }
        queue<int> q;
        for (int i = 0; i < prev.size(); i++)
            if (!prev[i])
                q.push(i);
        for ( ; !q.empty(); q.pop())
            for (int idx: next[q.front()])
                if (!--prev[idx])
                    q.push(idx);
        for (int n: prev)
            if (n)
                return false;
        return true;
    }
};