class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (!matrix.empty()) {
            int dx[] = {0, 1, 0, -1},
                dy[] = {1, 0, -1, 0},
                il = 0,
                ir = matrix.size() - 1,
                jl = 0,
                jr = matrix[0].size() - 1;
            result.push_back(matrix[0][0]);
            for (int x = 0, y = 0, d = 0; il <= ir && jl <= jr; d = d + 1 & 3) {
                while (il <= x + dx[d] && x + dx[d] <= ir && jl <= y + dy[d] && y + dy[d] <= jr)
                    result.push_back(matrix[x += dx[d]][y += dy[d]]);
                switch (d) {
                    case 0:il++;break;
                    case 1:jr--;break;
                    case 2:ir--;break;
                    case 3:jl++;break;
                }
            }
        }
        return result;
    }
};