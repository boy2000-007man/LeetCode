class Solution {
    struct range_sum {
        vector<vector<int>> sum;
        range_sum(vector<vector<char>> &matrix) {
            for (auto &v: matrix)
                sum.push_back(vector<int>(v.size()));
            for (int i = 0; i < sum.size(); i++)
                for (int j = 0; j < sum[i].size(); j++) {
                    sum[i][j] = matrix[i][j] == '1';
                    if (i)
                        sum[i][j] += sum[i - 1][j];
                    if (j)
                        sum[i][j] += sum[i][j - 1];
                    if (i && j)
                        sum[i][j] -= sum[i - 1][j - 1];
                }
        }
        int search(int i, int j, int l) {
            if (i && j)
                return sum[i + l - 1][j + l - 1] - sum[i - 1][j + l - 1] - sum[i + l - 1][j - 1] + sum[i - 1][j - 1];
            else if (i)
                return sum[i + l - 1][j + l - 1] - sum[i - 1][j + l - 1];
            else if (j)
                return sum[i + l - 1][j + l - 1] - sum[i + l - 1][j - 1];
            else
                return sum[i + l - 1][j + l - 1];
        }
    };
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int len = 0;
        range_sum rs(matrix);
        for (int i = 0; i + len < matrix.size(); i++)
            for (int j = 0; i + len < matrix.size() && j + len < matrix[i].size(); j++)
                while (i + len < matrix.size() && j + len < matrix[i].size() && rs.search(i, j, len + 1) == pow(len + 1, 2))
                    len++;
        return pow(len, 2);
    }
};