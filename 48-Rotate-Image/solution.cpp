class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() >> 1; i++)
            for (int j = 0; j < matrix[i].size() + 1 >> 1; j++) {
                swap(matrix[i][j], matrix[j][matrix[i].size() - 1 - i]);
                swap(matrix[i][j], matrix[matrix.size() - 1 - i][matrix[i].size() - 1 - j]);
                swap(matrix[i][j], matrix[matrix.size() - 1 - j][i]);
            }
    }
};