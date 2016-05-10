class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = -1,
            c;
        for (int i = 0; i < matrix.size() && r < 0; i++)
            for (int j = 0; j < matrix[i].size() && r < 0; j++)
                if (!matrix[i][j])
                    r = i, c = j;
        if (0 <= r) {
            for (int i = 0; i < matrix.size(); i++)
                for (int j = 0; j < matrix[i].size(); j++)
                    if (!matrix[i][j])
                        matrix[r][j] = matrix[i][c] = 0;
            for (int i = 0; i < matrix.size(); i++)
                if (i != r && !matrix[i][c])
                    for (int j = 0; j < matrix[i].size(); j++)
                        matrix[i][j] = 0;
            for (int j = 0; j < matrix[r].size(); j++)
                if (j != c && !matrix[r][j])
                    for (int i = 0; i < matrix.size(); i++)
                        matrix[i][j] = 0;
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][c] = 0;
            for (int j = 0; j < matrix[r].size(); j++)
                matrix[r][j] = 0;
        }
    }
};