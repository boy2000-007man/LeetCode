class Solution {
public:
    int climbStairs(int n) {
        vector<int> num(2, 1);
        for (int i = 2; i <= n; i++)
            num[i & 1] += num[~i & 1];
        return num[n & 1];
    }
};