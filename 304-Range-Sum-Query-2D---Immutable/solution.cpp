class NumMatrix {
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> &matrix) : sum(matrix) {
        for (int i = 0; i < sum.size(); i++)
            for (int j = 0; j < sum[i].size(); j++)
                if (i && j)
                    sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
                else if (i)
                    sum[i][j] += sum[i - 1][j];
                else if (j)
                    sum[i][j] += sum[i][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 && col1)
            return sum[row2][col2] - sum[row2][col1 - 1] - sum[row1 - 1][col2] + sum[row1 - 1][col1 - 1];
        else if (row1)
            return sum[row2][col2] - sum[row1 - 1][col2];
        else if (col1)
            return sum[row2][col2] - sum[row2][col1 - 1];
        else
            return sum[row2][col2];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);