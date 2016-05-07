class Solution {
public:
    int numTrees(int n) {
        vector<int> num(n + 1, 0);
        num[0] = 1;
        for (int i = 1; i < num.size(); i++)
            for (int j = 0; j < i; j++)
                num[i] += num[j] * num[i - 1 - j];
        return num[n];
    }
};