class Solution {
    static bool cmp(int target, const vector<int> &v1) {
        return target < v1[0];
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.empty() && !matrix[0].empty()) {
            auto it = upper_bound(matrix.begin(), matrix.end(), target, cmp);
            if (it-- != matrix.begin() && binary_search(it->begin(), it->end(), target))
                return true;
        }
        return false;
    }
};