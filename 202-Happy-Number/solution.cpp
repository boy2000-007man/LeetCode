class Solution {
public:
    bool isHappy(int n) {
        vector<bool> visit(1000, false);
        for (int t; n != 1; n = t) {
            for (t = 0; n; n /= 10)
                t += pow(n % 10, 2);
            if (visit[t])
                return false;
            visit[t] = true;
        }
        return true;
    }
};