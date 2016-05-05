class Solution {
    struct node {
        int in;
        vector<node *> next;
        node() : in(0), next(0) {
        }
    };
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<node>> m;
        for (auto &v: matrix)
            m.push_back(vector<node>(v.size()));
        int dx[] = {-1, 1, 0, 0},
            dy[] = {0, 0, -1, 1};
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k],
                        y = j + dy[k];
                    if (0 <= x && x < matrix.size() && 0 <= y && y < matrix[x].size() && matrix[i][j] < matrix[x][y]) {
                        m[i][j].next.push_back(&m[x][y]);
                        m[x][y].in++;
                    }
                }
        queue<node *> q;
        for (auto &v: m)
            for (auto &n: v)
                if (!n.in)
                    q.push(&n);
        int depth = 0;
        for (int num = 1; !q.empty(); q.pop()) {
            if (!--num) {
                depth++;
                num = q.size();
            }
            for (auto p: q.front()->next)
                if (!--p->in)
                    q.push(p);
        }
        return depth;
    }
};