class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int dx[] = {0, 1, 0, -1},
            dy[] = {1, 0, -1, 0},
            xl = 0,
            xr = n - 1,
            yl = 0,
            yr = n - 1;
        if (n)
            n = matrix[0][0] = 1;
        for (int x = 0, y = 0, d = 0; xl <= xr && yl <= yr; d = d + 1 & 3) {
            while (xl <= x + dx[d] && x + dx[d] <= xr && yl <= y + dy[d] && y + dy[d] <= yr)
                matrix[x += dx[d]][y += dy[d]] = ++n;
            switch (d) {
                case 0:xl++;break;
                case 1:yr--;break;
                case 2:xr--;break;
                case 3:yl++;break;
            }
        }
        return matrix;
    }
};