class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(),
            len2 = word2.length();
        if (len1 < len2) {
            word1.swap(word2);
            swap(len1, len2);
        }
        vector<vector<int>> result(len1 + 1, vector<int>(len2 + 1, len1));
        for (int i = 0; i <= len1; i++)
            for (int j = max(0, i + (len2 >> 1) - len1); j <= min(len2, i + (len2 >> 1)); j++)
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