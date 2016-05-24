class Solution {
public:
    void solve(vector<vector<char>>& board) {
        static int dx[] = {-1, 0, 0, 1},
                   dy[] = {0, -1, 1, 0};
        int m = board.size(),
            n = m ? board[0].size() : 0;
        if (m && n) {
            stack<pair<int, int>> stk;
            for (int i = 0; i < m; i++)
                if (board[i][0] == 'O')
                    stk.push({i, 0});
            for (int i = 0; i < m; i++)
                if (board[i][n - 1] == 'O')
                    stk.push({i, n - 1});
            for (int i = 0; i < n; i++)
                if (board[0][i] == 'O')
                    stk.push({0, i});
            for (int i = 0; i < n; i++)
                if (board[m - 1][i] == 'O')
                    stk.push({m - 1, i});
            while (!stk.empty()) {
                int x = stk.top().first,
                    y = stk.top().second;
                stk.pop();
                board[x][y] = 'o';
                for (int i = 0; i < 4; i++)
                    if (0 <= x + dx[i] && x + dx[i] < m && 0 <= y + dy[i] && y + dy[i] < n && board[x + dx[i]][y + dy[i]] == 'O')
                        stk.push({x + dx[i], y + dy[i]});
            }
            for (auto &v: board)
                for (char &c: v)
                    c = c == 'o' ? 'O' : 'X';
        }
    }
};