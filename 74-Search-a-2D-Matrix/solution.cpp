class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),
            n = m ? matrix[0].size() : 0;
        for (int l = 0, r = m * n - 1; l <= r; ) {
            int middle = l + r >> 1,
                x = middle / n,
                y = middle % n;
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] < target)
                l = middle + 1;
            else
                r = middle - 1;
        }
        return false;
    }
};