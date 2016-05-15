class Solution {
    void search(vector<vector<char>> &grid, int x, int y) {
        static int dx[] = {-1, 0, 0, 1},
                   dy[] = {0, -1, 1, 0};
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++)
            if (0 <= x + dx[i] && x + dx[i] < grid.size() && 0 <= y + dy[i] && y + dy[i] < grid[x].size()
            && grid[x + dx[i]][y + dy[i]] != '0')
                search(grid, x + dx[i], y + dy[i]);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] != '0') {
                    cnt++;
                    search(grid, i, j);
                }
        return cnt;
    }
};