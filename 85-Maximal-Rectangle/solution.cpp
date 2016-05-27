class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int area = 0;
        vector<int> heights(matrix.empty() ? 0 : matrix[0].size() + 1, 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++)
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j]++;
            stack<pair<int, int>> locs;
            for (int j = 0; j < heights.size(); j++) {
                int loc = j,
                    height = heights[loc];
                for ( ; !locs.empty() && height <= locs.top().second; locs.pop())
                    area = max(area, locs.top().second * (j - (loc = locs.top().first)));
                if (height)
                    locs.push({loc, height});
            }
        }
        return area;
    }
};