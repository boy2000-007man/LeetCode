class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (vector<int> line; result.size() < numRows; ) {
            for (int i = line.size() - 1; 0 < i; i--)
                line[i] += line[i - 1];
            line.push_back(1);
            result.push_back(line);
        }
        return result;
    }
};