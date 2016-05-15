class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> result(word1.length() + 1, vector<int>(word2.length() + 1, INT_MAX));
        for (int i = 0; i < result.size(); i++)
            for (int j = 0; j < result[i].size(); j++)
                if (!i && !j)
                    result[i][j] = 0;
                else {
                    if (i)
                        result[i][j] = min(result[i][j], result[i - 1][j] + 1);
                    if (j)
                        result[i][j] = min(result[i][j], result[i][j - 1] + 1);
                    if (i && j)
                        result[i][j] = min(result[i][j], result[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
                }
        return result.back().back();
    }
};