class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> num(m, 1);
        for (int i = 1; i < n; i++)
            for (int j = 1; j < num.size(); j++)
                num[j] += num[j - 1];
        return num.back();
    }
};